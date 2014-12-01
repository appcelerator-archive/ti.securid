var SecurID = require('ti.securid');
var u = Ti.Android != undefined ? 'dp' : 0;
var png = Ti.Android ? '@2x.png' : '.png';

var win = Ti.UI.createWindow({
    backgroundColor: '#fff'
});

var fob = Ti.UI.createView({
    backgroundImage: 'fob' + png,
    width: 354 + u, height: 175 + u,
    top: 25 + u
});
win.add(fob);

var next = Ti.UI.createView({
    backgroundImage: 'next' + png,
    width: 49 + u, height: 24 + u,
    bottom: 37 + u, right: 40 + u
});
next.hide();
fob.add(next);

var fontSize = 25;
if (Ti.Platform.name === 'iPhone OS') {
    fontSize = 18;
}
var status = Ti.UI.createLabel({
    text: 'Loading...', textAlign: 'left',
    height: 30 + u, color: '#000',
    font: { fontSize: fontSize, fontWeight: 'bold' },
    top: 68 + u, right: 0, left: 180 + u
});
fob.add(status);

var time = Ti.UI.createLabel({
    text: '', textAlign: 'left',
    height: 15 + u, color: '#000',
    opacity: 0.7,
    font: { fontSize: 12 },
    top: 89 + u, right: 0, left: 180 + u
});
fob.add(time);

// Listen for Errors
SecurID.addEventListener('error', function (evt) {
    Ti.API.error(evt);
    status.text = 'Error!';
    time.text = '';
});

win.add(Ti.UI.createLabel({
    text: 'Library Info: ' + SecurID.libraryInfo, textAlign: 'center',
    color: '#000',
    height: 25 + u,
    top: 220 + u, right: 0, left: 0
}));
win.add(Ti.UI.createLabel({
    text: 'Device Id: ' + SecurID.deviceId, textAlign: 'center',
    color: '#000',
    height: 25 + u,
    top: 240 + u, right: 0, left: 0
}));

win.addEventListener('open', function () {

    // Import token from Ctf string
    SecurID.importTokenFromCtf(
        '200002705010546272071630155757023372676563314143545673224170521746247102716734010',
        ''
    );

    // Get Tokens
    var tokens = SecurID.retrieveTokens();

    // Check to make sure we have a couple of tokens.
    if (tokens.length > 0) {

        // Get OTP
        var otp = SecurID.retrieveOtp(
            tokens[0].serialNumber,
            '1234'
        );
        status.text = 'OTP: ' + otp.otp;

        var countTo = new Date().getTime() + (otp.timeRemaining * 1000);

        setInterval(function () {
            var now = new Date().getTime();
            if (countTo < now) {
                status.text = 'OTP: Expired!';
                time.text = '';
                next.show();
            }
            else {
                time.text = parseInt((countTo - now) / 1000, 10) + ' seconds remaining...';
            }
        }, 200);

        next.addEventListener('click', function (evt) {
            otp = SecurID.retrieveNextOtp(
                tokens[0].serialNumber,
                ''
            );
            status.text = 'OTP: ' + otp.otp;
            countTo = new Date().getTime() + (otp.timeRemaining * 1000);
            next.hide();
        });
    }
    else {
        status.text = 'Invalid CTF!';
        time.text = '';
    }
});

win.open();