//
//  SecurIDLibStatus.h
//  SecurIDLib
//
//  Copyright (c) 2010-2012 EMC Corporation. All Rights Reserved.
//


/*!
 * SecurID library status codes.
 */
typedef enum _SECURIDLIB_STATUS
    {
        /*! \brief Success. */
        SECURIDLIB_ERR_SUCCESS = 0,
        /*! \brief Generic error. */
        SECURIDLIB_ERR_FAILURE = 50,

        /*! \brief Invalid parameter error. */
        SECURIDLIB_ERR_PARAMETER = 51,
        /*! \brief Invalid CTF parameter error. */
        SECURIDLIB_ERR_PARAMETER_CTF = 52,
        /*! \brief Invalid serial number parameter error. */
        SECURIDLIB_ERR_PARAMETER_SN = 53,
        /*! \brief Invalid URL parameter error. */
        SECURIDLIB_ERR_PARAMETER_URL = 54,
        /*! \brief Invalid activation code parameter error. */
        SECURIDLIB_ERR_PARAMETER_AUTHCODE = 55,
        /*! \brief Invalid delegate parameter error. */
        SECURIDLIB_ERR_PARAMETER_DELEGATE = 56,
        /*! \brief Invalid OTP parameter error. */
        SECURIDLIB_ERR_PARAMETER_OTP = 57,
        /*! \brief Invalid seconds remaining parameter error. */
        SECURIDLIB_ERR_PARAMETER_SECS = 58,
        /*! \brief Invalid PIN parameter error. */
        SECURIDLIB_ERR_PARAMETER_PIN = 59,

		/*! \brief CTF record parsing error. */
        SECURIDLIB_ERR_CTF_PARSE = 60,
        /*! \brief CTF password error. */
        SECURIDLIB_ERR_CTF_PASSWORD = 61,
        /*! \brief CTF device binding error. */
        SECURIDLIB_ERR_CTF_DEVICEID = 62,

        /*! \brief CT-KIP wireless service disabled. */
        SECURIDLIB_ERR_CTKIP_WIRELESS_SERVICE = 63,
        /*! \brief CT-KIP network error. */
        SECURIDLIB_ERR_CTKIP_NETWORK = 64,
        /*! \brief CT-KIP SSL certificate validation error. */
        SECURIDLIB_ERR_CTKIP_SSL_CERTIFICATE = 65,
        /*! \brief CT-KIP unhandled exception error. */
        SECURIDLIB_ERR_CTKIP_EXCEPTION = 66,
        /*! \brief CT-KIP invalid activation code detected. */
        SECURIDLIB_ERR_CTKIP_INVALID_AUTHCODE = 67,

        /*! \brief CT-KIP network packet processing error. */
        SECURIDLIB_ERR_CTKIP_PACKET_PROCESSING = 68,
        /*! \brief CT-KIP device binding error. */
        SECURIDLIB_ERR_CTKIP_DEVICEID = 69,

		/*! \brief Token not found. */
        SECURIDLIB_ERR_NO_TOKEN = 70,
        /*! \brief Token expired. */
        SECURIDLIB_ERR_TOKEN_EXPIRED = 71,
        /*! \brief Database copy-protection error. */
        SECURIDLIB_ERR_COPY_PROTECTION = 72,
        /*! \brief Database persistence error. */
        SECURIDLIB_ERR_PERSISTENCE = 73,
        /*! \brief Token exists. Duplicate token error.  */
        SECURIDLIB_ERR_DUPLICATE_TOKEN = 74,
        /*! \brief Maximum token limit reached.  */
        SECURIDLIB_ERR_MAX_TOKEN_LIMIT = 75,
		
		/*! \brief Token file parsing error. */
        SECURIDLIB_ERR_FILE_PARSE = 76,
        /*! \brief Token file password error. */
        SECURIDLIB_ERR_FILE_PASSWORD = 77,
        /*! \brief Token file device binding error. */
        SECURIDLIB_ERR_FILE_DEVICEID = 78,
		/*! \brief Invalid token file data parameter error. */
        SECURIDLIB_ERR_PARAMETER_FILE = 79,
        /*! \brief Data protection error. */
        SECURIDLIB_ERR_DATA_PROTECTION = 80,
        
        /*! \brief Transaction data payload XSD validation error. */
        SECURIDLIB_ERR_TDP_XSD_VALIDATION = 81,     
        /*! \brief Transaction data payload XML parse error. */
        SECURIDLIB_ERR_TDP_XML_PARSE = 82,
        /*! \brief Transaction data payload missing required data error. */
        SECURIDLIB_ERR_TDP_DATA_MISSING = 83,
        /*! \brief Transaction data payload integrity check error. */
		SECURIDLIB_ERR_TDP_INTEGRITY = 84,  
        /*! \brief Transaction data payload crypto error. */
        SECURIDLIB_ERR_TDP_CRYPTO = 85,
        /*! \brief Transaction data payload invalid operation error. */
        SECURIDLIB_ERR_TDP_INVALID_OPERATION = 86
        
    } SECURIDLIB_STATUS;



/*!
 * The domain identifier for SecurID library NSError objects.
 */
extern NSString* SecurIDLibDomain;

/*!
 * The version key for TDP dictionary.
 */
extern NSString* SECURIDLIB_TDP_VERSION_KEY;
/*!
 * The time key for TDP dictionary.
 */
extern NSString* SECURIDLIB_TDP_TIME_KEY;
/*!
 * The token serial number key for TDP dictionary.
 */
extern NSString* SECURIDLIB_TDP_SERIAL_NUMBER_KEY;
/*!
 * The transaction ID key for TDP dictionary.
 */
extern NSString* SECURIDLIB_TDP_TRANSACTION_ID_KEY;
/*!
 * The transaction data key for TDP dictionary.
 */
extern NSString* SECURIDLIB_TDP_TRANSACTION_DATA_KEY;


