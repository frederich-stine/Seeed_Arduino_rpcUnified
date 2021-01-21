/*
 * Generated by erpcgen 1.7.4 on Thu Jan 21 15:15:43 2021.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_rpc_system_header_h_)
#define _rpc_system_header_h_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "erpc_version.h"

#if 10704 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

#if !defined(ERPC_TYPE_DEFINITIONS)
#define ERPC_TYPE_DEFINITIONS

// Enumerators data types declarations
/** @brief GAP Cause List */
typedef enum RPC_T_GAP_CAUSE
{
    RPC_GAP_CAUSE_SUCCESS = 0,//!< Operation success.
    RPC_GAP_CAUSE_ALREADY_IN_REQ = 1,//!< Operation already in progress.
    RPC_GAP_CAUSE_INVALID_STATE = 2,//!< Invalid state.
    RPC_GAP_CAUSE_INVALID_PARAM = 3,//!< Invalid parameter.
    RPC_GAP_CAUSE_NON_CONN = 4,//!< No connection establishment.
    RPC_GAP_CAUSE_NOT_FIND_IRK = 5,//!< IRK not found.
    RPC_GAP_CAUSE_ERROR_CREDITS = 6,//!< Credits error.
    RPC_GAP_CAUSE_SEND_REQ_FAILED = 7,//!< Send Request failed.
    RPC_GAP_CAUSE_NO_RESOURCE = 8,//!< No resource.
    RPC_GAP_CAUSE_INVALID_PDU_SIZE = 9,//!< Invalid PDU size.
    RPC_GAP_CAUSE_NOT_FIND = 10,//!< Not Found.
    RPC_GAP_CAUSE_CONN_LIMIT = 11,//!< Connection reachs limited count.
    RPC_GAP_CAUSE_NO_BOND = 12,//!< No Bond.
    RPC_GAP_CAUSE_ERROR_UNKNOWN = 255//!< Unknown error.
} RPC_T_GAP_CAUSE;

typedef enum RPC_T_APP_RESULT
{
    RPC_APP_RESULT_SUCCESS = 0,
    RPC_APP_RESULT_PENDING = 3329,
    RPC_APP_RESULT_ACCEPT = 3331,
    RPC_APP_RESULT_REJECT = 3332,
    RPC_APP_RESULT_NOT_RELEASE = 3333,
    RPC_APP_RESULT_PREP_QUEUE_FULL = 1033,
    RPC_APP_RESULT_INVALID_OFFSET = 1031,
    RPC_APP_RESULT_INVALID_VALUE_SIZE = 1037,
    RPC_APP_RESULT_INVALID_PDU = 1028,
    RPC_APP_RESULT_ATTR_NOT_FOUND = 1034,
    RPC_APP_RESULT_ATTR_NOT_LONG = 1035,
    RPC_APP_RESULT_INSUFFICIENT_RESOURCES = 1041,
    RPC_APP_RESULT_APP_ERR = 1152,
    RPC_APP_RESULT_CCCD_IMPROPERLY_CONFIGURED = 1277,
    RPC_APP_RESULT_PROC_ALREADY_IN_PROGRESS = 1278
} RPC_T_APP_RESULT;

/** @brief LE advertising parameter types */
typedef enum RPC_T_LE_ADV_PARAM_TYPE
{
    RPC_GAP_PARAM_ADV_LOCAL_ADDR_TYPE = 608, //!< Advertisement used local bluetooth device address type. Read/Write Size is uint8.
    RPC_GAP_PARAM_ADV_DATA = 609, //!< Advertisement Data. Read/Write. Max size is uint8[GAP_MAX_ADV_LEN]. Default is "02:01:05", which means that it is a Limited Discoverable Advertisement.
    RPC_GAP_PARAM_SCAN_RSP_DATA = 610, //!< Scan Response Data. Read/Write. Max size is uint8[GAP_MAX_ADV_LEN]. Defaults to all 0.
    RPC_GAP_PARAM_ADV_EVENT_TYPE = 611, //!< Advertisement Type. Read/Write. Size is uint8.  Default is GAP_ADTYPE_ADV_IND (@ref T_GAP_ADTYPE).
    RPC_GAP_PARAM_ADV_DIRECT_ADDR_TYPE = 612, //!< Direct Advertisement Address Type. Read/Write. Size is uint8.
    RPC_GAP_PARAM_ADV_DIRECT_ADDR = 613, //!< Direct Advertisement Address. Read/Write. Size is uint8[GAP_BD_ADDR_LEN]. Default is NULL.
    RPC_GAP_PARAM_ADV_CHANNEL_MAP = 614, //!< Which channels to advertise on. Read/Write Size is uint8. Default is GAP_ADVCHAN_ALL (@ref ADV_CHANNEL_MAP)
    RPC_GAP_PARAM_ADV_FILTER_POLICY = 615, //!< Filter Policy. Ignored when directed advertising is used. Read/Write. Size is uint8. Default is GAP_ADV_FILTER_ANY (@ref T_GAP_ADV_FILTER_POLICY).
    RPC_GAP_PARAM_ADV_INTERVAL_MIN = 616, //!< Minimum advertising interval for undirected and low duty cycle directed advertising. Value range: 0x0020 - 0x4000 (20ms - 10240ms 0.625ms/step),Read/Write Size is uint16_t.
    RPC_GAP_PARAM_ADV_INTERVAL_MAX = 617 //!< Maximum advertising interval for undirected and low duty cycle directed  advertising. Value range: 0x0020 - 0x4000 (20ms - 10240ms 0.625ms/step)),Read/Write Size is uint16_t.
} RPC_T_LE_ADV_PARAM_TYPE;

/** @brief  GAP LE Parameter Types List.*/
typedef enum RPC_T_GAP_LE_PARAM_TYPE
{
    RPC_GAP_PARAM_DEV_STATE = 544, //!< Device's current GAP device state. Read/Write. Size is sizeof(TGapDevState).
    RPC_GAP_PARAM_APPEARANCE = 545, //!< Local Device's Appearance. Read/Write. size is uint16. Appearance value please refer to GAP Appearance Values.(@ref GAP_LE_APPEARANCE_VALUES)
    RPC_GAP_PARAM_DEVICE_NAME = 546, //!< Local Device's Name. Write Only. Name string length is GAP_DEVICE_NAME_LEN.
    RPC_GAP_PARAM_SLAVE_INIT_GATT_MTU_REQ = 547, //!< Slave initiate the GATT exchange MTU procedure. Write Only.
    RPC_GAP_PARAM_RANDOM_ADDR = 548, //!< Random address. Write Only.
    RPC_GAP_PARAM_LATEST_CONN_BD_ADDR = 550, //!< Latest connected bluetooth devive address. Read Only.
    RPC_GAP_PARAM_LATEST_CONN_BD_ADDR_TYPE = 551, //!< Latest connected bluetooth devive address type. Read Only.
    RPC_GAP_PARAM_HANDLE_CREATE_CONN_IND = 552, //!< App handle the create connection indication message.
    RPC_GAP_PARAM_DEFAULT_PHYS_PREFER = 553, //!< Preferred values for the transmitter PHY and receiver PHY to be used for all subsequent connections over the LE transport.
    RPC_GAP_PARAM_DEFAULT_TX_PHYS_PREFER = 554, //!< The transmitter PHYs that the Host prefers the Controller to use.
    RPC_GAP_PARAM_DEFAULT_RX_PHYS_PREFER = 555, //!< The receiver PHYs that the Host prefers the Controller to use.
    RPC_GAP_PARAM_DEFAULT_DATA_LEN_MAX_TX_OCTETS = 558,
    RPC_GAP_PARAM_DEFAULT_DATA_LEN_MAX_TX_TIME = 559,
    RPC_GAP_PARAM_LOCAL_FEATURES = 560, //!< Local supported features.
    RPC_GAP_PARAM_DS_POOL_ID = 561, //!< Downstream PoolID.  Read only.  size is uint16.
    RPC_GAP_PARAM_DS_DATA_OFFSET = 562, //!< Downstream pool buffer data offset.  Read only.  size is uint16.
    RPC_GAP_PARAM_LE_REMAIN_CREDITS = 563, //!< Remain credits avaiable for TX.  Read only.  size is uint16.
    RPC_GAP_PARAM_MAX_WL_SIZE = 564 //!< Max white list size.  Read only.  size is uint16.
} RPC_T_GAP_LE_PARAM_TYPE;

/** @brief LE scan parameter type */
typedef enum RPC_T_LE_SCAN_PARAM_TYPE
{
    RPC_GAP_PARAM_SCAN_LOCAL_ADDR_TYPE = 576,  //!< The type of address being used in the scan request packets. Read/Write.
    RPC_GAP_PARAM_SCAN_MODE = 577,  //!< Scan mode. Read/Write. Size is uint8. Default is GAP_SCAN_MODE_ACTIVE (@ref T_GAP_SCAN_MODE).
    RPC_GAP_PARAM_SCAN_INTERVAL = 578,  //!< Scan Interval. Read/Write. Size is uint16_t. Default is 0x10. Value range: 0x0004 - 0x4000 (2.5ms - 10240ms 0.625ms/step).
    RPC_GAP_PARAM_SCAN_WINDOW = 579,  //!< Scan Window. Read/Write. Size is uint16_t. Default is 0x10. Value range: 0x0004 - 0x4000 (2.5ms - 10240ms 0.625ms/step).
    RPC_GAP_PARAM_SCAN_FILTER_POLICY = 580,  //!< Scan Filter Policy.Read/Write. Size is uint8_t. Default is GAP_SCAN_FILTER_ANY (@ref T_GAP_SCAN_FILTER_POLICY).
    RPC_GAP_PARAM_SCAN_FILTER_DUPLICATES = 581   //!< Scan Filter Duplicates.Read/Write. Size is uint8_t. Default is GAP_SCAN_FILTER_DUPLICATE_DISABLE (@ref T_GAP_SCAN_FILTER_DUPLICATE).
} RPC_T_LE_SCAN_PARAM_TYPE;

/** @brief  Definition of LE white list operation.*/
typedef enum RPC_T_GAP_WHITE_LIST_OP
{
    RPC_GAP_WHITE_LIST_OP_CLEAR = 0,    /**<  Clear white list. */
    RPC_GAP_WHITE_LIST_OP_ADD = 1,          /**<  Add a device to the white list. */
    RPC_GAP_WHITE_LIST_OP_REMOVE = 2        /**<  Remove a device from the white list. */
} RPC_T_GAP_WHITE_LIST_OP;

/** @brief GAP Remote Address Type */
typedef enum RPC_T_GAP_REMOTE_ADDR_TYPE
{
    RPC_GAP_REMOTE_ADDR_LE_PUBLIC = 0, /**< LE Public device address type. */
    RPC_GAP_REMOTE_ADDR_LE_RANDOM = 1 /**< LE Random device address type. */
} RPC_T_GAP_REMOTE_ADDR_TYPE;

/** @brief Define random adress type */
typedef enum RPC_T_GAP_RAND_ADDR_TYPE
{
    RPC_GAP_RAND_ADDR_STATIC = 0,/**<  Static random device address. */
    RPC_GAP_RAND_ADDR_NON_RESOLVABLE = 1,/**<  Non resolvable random device address. */
    RPC_GAP_RAND_ADDR_RESOLVABLE = 2 /**<  Resolvable random device address. */
} RPC_T_GAP_RAND_ADDR_TYPE;

/** @brief Define indentify address type */
typedef enum RPC_T_GAP_IDENT_ADDR_TYPE
{
    RPC_GAP_IDENT_ADDR_PUBLIC = 0,
    RPC_GAP_IDENT_ADDR_RAND = 1
} RPC_T_GAP_IDENT_ADDR_TYPE;

/** @brief GAP gatt cccd not check. */
typedef enum RPC_T_GAP_CONFIG_GATT_CCCD_NOT_CHECK
{
    RPC_CONFIG_GATT_CCCD_CHECK = 0,         /**< Check cccd when server sends notification or indication. */
    RPC_CONFIG_GATT_CCCD_NOT_CHECK = 1     /**< Not check cccd when server sends notification or indication. */
} RPC_T_GAP_CONFIG_GATT_CCCD_NOT_CHECK;

/** @brief GAP Parameter List */
typedef enum RPC_T_GAP_PARAM_TYPE
{
    RPC_GAP_PARAM_BD_ADDR = 512,//!< Locol Device's Address. Read Only. Size is uint8[GAP_BD_ADDR_LEN]. This item is read from the controller.
    RPC_GAP_PARAM_BOND_PAIRING_MODE = 514,//!< Pairing Mode of LE and BR/EDR. Write Only. Size is uint8_t. Default is GAP_PAIRING_MODE_PAIRABLE (@ref BOND_PAIRING_MODE_DEFINES).
    RPC_GAP_PARAM_BOND_AUTHEN_REQUIREMENTS_FLAGS = 515,//!< Man-In-The-Middle (MITM) basically turns on Passkey protection in the pairing algorithm. Read/Write. Size is uint8_t. Default is GAP_AUTHEN_NO_MITM_YES_BOND (@ref BOND_MITM_DEFINES).
    RPC_GAP_PARAM_BOND_IO_CAPABILITIES = 516,//!< I/O capabilities.  Read/Write. Size is uint8_t. Default is GAP_IO_CAP_NO_INPUT_NO_OUTPUT (@ref T_GAP_IO_CAP).
    RPC_GAP_PARAM_BOND_OOB_ENABLED = 517,//!< OOB data available for pairing algorithm. Read/Write. Size is uint8_t. Default is 0(disabled).
    RPC_GAP_PARAM_BOND_LE_PAIRING_MODE = 519//!< LE Pairing Mode. Read/Write. Size is uint8_t. Default is GAP_PAIRING_MODE_PAIRABLE (@ref BOND_PAIRING_MODE_DEFINES).
} RPC_T_GAP_PARAM_TYPE;

/** @brief LE bond parameter types */
typedef enum RPC_T_LE_BOND_PARAM_TYPE
{
    RPC_GAP_PARAM_BOND_OOB_DATA = 528,//!< OOB Data. Read/Write. size uint8_t[16]. Default is all 0's.
    RPC_GAP_PARAM_BOND_FIXED_PASSKEY = 529,//!< The fix passcode for MITM protection. Read/Write. size is uint32_t. Range is 0 - 999,999. Default is 0.
    RPC_GAP_PARAM_BOND_FIXED_PASSKEY_ENABLE = 530,//!< The fix passcode available for pairing. Read/Write. size is uint8_t. Default is 0(disabled).
    RPC_GAP_PARAM_BOND_SEC_REQ_ENABLE = 531,//!< Send smp security request when connected. Read/Write. size is uint8_t. Default is 0(disabled).
    RPC_GAP_PARAM_BOND_SEC_REQ_REQUIREMENT = 532,//!< Security request requirements. Read/Write. size is uint8_t. Default is GAP_AUTHEN_BIT_BONDING_FLAG (@ref BOND_MITM_DEFINES)
    RPC_GAP_PARAM_BOND_MIN_KEY_SIZE = 533,//!< Minium LTK size required. Read/Write. size is uint8_t.
    RPC_GAP_PARAM_BOND_KEY_MANAGER = 536,//!< Key manager. Write only. size is uint8_t. Default is 0(disabled).
    RPC_GAP_PARAM_BOND_SIGN_KEY_FLAG = 537//!< Sign key flag configure. Write only. size is uint8_t. Default is 0(disabled).
} RPC_T_LE_BOND_PARAM_TYPE;

/** @brief  GAP Confirmation Cause List */
typedef enum RPC_T_GAP_CFM_CAUSE
{
    RPC_GAP_CFM_CAUSE_ACCEPT = 1,    /**< Accept for indication, only used when confirmation. */
    RPC_GAP_CFM_CAUSE_REJECT = 2    /**< Reject for indication, only used when confirmation. */
} RPC_T_GAP_CFM_CAUSE;

/** @brief Definition of security level. */
typedef enum RPC_T_GAP_SEC_LEVEL
{
    RPC_GAP_SEC_LEVEL_NO = 0,   /**< No security (No authentication and no encryption).*/
    RPC_GAP_SEC_LEVEL_UNAUTHEN = 4,   /**< Unauthenticated pairing with encryption.*/
    RPC_GAP_SEC_LEVEL_AUTHEN = 5,   /**< Authenticated pairing with encryption.*/
    RPC_GAP_SEC_LEVEL_SC_UNAUTHEN = 7,   /**< Unuthenticated LE Secure Connections pairing with encryption using a 128-bit strength encryption key.*/
    RPC_GAP_SEC_LEVEL_SC_AUTHEN = 8    /**< Authenticated LE Secure Connections pairing with encryption using a 128-bit strength encryption key.*/
} RPC_T_GAP_SEC_LEVEL;

/** @brief LE connection parameter types */
typedef enum RPC_T_LE_CONN_PARAM_TYPE
{
    RPC_GAP_PARAM_CONN_BD_ADDR = 624, //!< Address of connected device. Read only. Size is uint8[B_MAX_ADV_LEN]. Set to all zeros when not connected.
    RPC_GAP_PARAM_CONN_BD_ADDR_TYPE = 625, //!< Address type of connected device. Read only. Size is uint8. Set to zero when not connected.
    RPC_GAP_PARAM_CONN_INTERVAL = 626, //!< Current connection interval.  Read only. Size is uint16.  Range is 7.5ms to 4 seconds (0x0006 to 0x0C80).  Default is 0 (no connection).
    RPC_GAP_PARAM_CONN_LATENCY = 627, //!< Current slave latency.  Read only.  Size is uint16.  Range is 0 to 499. Default is 0 (no slave latency or no connection).
    RPC_GAP_PARAM_CONN_TIMEOUT = 628, //!< Current timeout value.  Read only.  size is uint16.  Range is 100ms to 32 seconds.  Default is 0 (no connection).
    RPC_GAP_PARAM_CONN_MTU_SIZE = 629, //!< MTU size.  Read only.  size is uint16.
    RPC_GAP_PARAM_CONN_LOCAL_BD_TYPE = 630, //!< Local bluetooth address type.  Read only.  size is 1 byte.
    RPC_GAP_PARAM_CONN_RX_PHY_TYPE = 631, //!< Rx phy type.  Read only.  size is 1 byte.
    RPC_GAP_PARAM_CONN_TX_PHY_TYPE = 632, //!< Tx phy type.  Read only.  size is 1 byte.
    RPC_GAP_PARAM_CONN_REMOTE_FEATURES = 633, //!< Remote supported features.  Read only.
    RPC_GAP_PARAM_CONN_HANDLE = 635 //!< LE link connection handle. Read only.
} RPC_T_LE_CONN_PARAM_TYPE;

/** @brief GAP connection states*/
typedef enum RPC_T_GAP_CONN_STATE
{
    RPC_GAP_CONN_STATE_DISCONNECTED = 0, //!< Disconnected.
    RPC_GAP_CONN_STATE_CONNECTING = 1,   //!< Connecting.
    RPC_GAP_CONN_STATE_CONNECTED = 2,    //!< Connected.
    RPC_GAP_CONN_STATE_DISCONNECTING = 3 //!< Disconnecting.
} RPC_T_GAP_CONN_STATE;

/** @brief GAP link roles */
typedef enum RPC_T_GAP_ROLE
{
    RPC_GAP_LINK_ROLE_UNDEFINED = 0,    //!< Unknown.
    RPC_GAP_LINK_ROLE_MASTER = 1,       //!< Role is master.
    RPC_GAP_LINK_ROLE_SLAVE = 2         //!< Role is slave.
} RPC_T_GAP_ROLE;

/** @brief  Definition of LE Coded PHY preference options.*/
typedef enum RPC_T_GAP_PHYS_OPTIONS
{
    RPC_GAP_PHYS_OPTIONS_CODED_PREFER_NO = 0,/**< Host has no preferred coding when transmitting on the LE Coded PHY */
    RPC_GAP_PHYS_OPTIONS_CODED_PREFER_S2 = 1,/**< Host prefers that S=2 coding be used when transmitting on the LE Coded PHY */
    RPC_GAP_PHYS_OPTIONS_CODED_PREFER_S8 = 2 /**< Host prefers that S=8 coding be used when transmitting on the LE Coded PHY */
} RPC_T_GAP_PHYS_OPTIONS;

/** @brief GAP connection phy types*/
typedef enum RPC_T_GAP_CONN_PARAM_TYPE
{
    RPC_GAP_CONN_PARAM_1M = 0
} RPC_T_GAP_CONN_PARAM_TYPE;

/** @brief LE Key Type */
typedef enum RPC_T_LE_KEY_TYPE
{
    RPC_LE_KEY_UNAUTHEN = 4, /**< SSP generated link key without MITM protection. */
    RPC_LE_KEY_AUTHEN = 5, /**< SSP generated link key with MITM protection. */
    RPC_LE_KEY_UNAUTHEN_P256 = 7, /**< Security Connections generated link key without MITM protection. */
    RPC_LE_KEY_AUTHEN_P256 = 8 /**< Security Connections link key with MITM protection. */
} RPC_T_LE_KEY_TYPE;

/** @brief define local adress type */
typedef enum RPC_T_GAP_LOCAL_ADDR_TYPE
{
    RPC_GAP_LOCAL_ADDR_LE_PUBLIC = 0,    /**<  Bluetooth low energy public address. */
    RPC_GAP_LOCAL_ADDR_LE_RANDOM = 1    /**<  Bluetooth low energy random address. */
} RPC_T_GAP_LOCAL_ADDR_TYPE;

/** @brief  GATT write type*/
typedef enum RPC_T_GATT_WRITE_TYPE
{
    RPC_GATT_WRITE_TYPE_REQ = 1,           /**<  ATT "Write Request"  */
    RPC_GATT_WRITE_TYPE_CMD = 2,           /**<  ATT "Write Command"  */
    RPC_GATT_WRITE_TYPE_SIGNED_CMD = 4     /**<  ATT "Signed Write Command"  */
} RPC_T_GATT_WRITE_TYPE;

/** @brief  GATT PDU type*/
typedef enum RPC_T_GATT_PDU_TYPE
{
    RPC_GATT_PDU_TYPE_ANY = 0, /**<  Any PDU type. */
    RPC_GATT_PDU_TYPE_NOTIFICATION = 1, /**<  Notification PDU type. */
    RPC_GATT_PDU_TYPE_INDICATION = 2  /**<  Indication PDU type. */
} RPC_T_GATT_PDU_TYPE;

/** @brief Event type to inform app*/
typedef enum RPC_T_SERVICE_CALLBACK_TYPE
{
    RPC_SERVICE_CALLBACK_TYPE_INDIFICATION_NOTIFICATION = 1,    /**< CCCD update event */
    RPC_SERVICE_CALLBACK_TYPE_READ_CHAR_VALUE = 2,              /**< client read event */
    RPC_SERVICE_CALLBACK_TYPE_WRITE_CHAR_VALUE = 3             /**< client write event */
} RPC_T_SERVICE_CALLBACK_TYPE;

// Aliases data types declarations
typedef struct binary_t binary_t;
typedef struct RPC_T_GAP_CONN_INFO RPC_T_GAP_CONN_INFO;
typedef struct RPC_T_GAP_LE_CONN_REQ_PARAM RPC_T_GAP_LE_CONN_REQ_PARAM;
typedef struct RPC_T_LOCAL_NAME RPC_T_LOCAL_NAME;
typedef struct RPC_T_LOCAL_APPEARANCE RPC_T_LOCAL_APPEARANCE;
typedef struct RPC_T_LOCAL_IRK RPC_T_LOCAL_IRK;
typedef struct RPC_T_LE_REMOTE_BD RPC_T_LE_REMOTE_BD;
typedef struct RPC_T_LE_CCCD RPC_T_LE_CCCD;
typedef struct RPC_T_LE_KEY_ENTRY RPC_T_LE_KEY_ENTRY;

// Structures/unions data types declarations
struct binary_t
{
    uint8_t * data;
    uint32_t dataLength;
};

/** @brief  Connected device information.*/
struct RPC_T_GAP_CONN_INFO
{
    RPC_T_GAP_CONN_STATE conn_state;             //!< Connection state
    RPC_T_GAP_ROLE role;                   //!< Device role
    uint8_t remote_bd[6];              //!< Remote address
    uint8_t remote_bd_type;         //!< Remote address type
};

/** @brief  Definition of LE connection request parameter.*/
struct RPC_T_GAP_LE_CONN_REQ_PARAM
{
    uint16_t scan_interval;/**< Time interval from when the Controller started its last scan
                                until it begins the subsequent scan on the primary advertising channel.

                                Range: 0x0004 to 0x4000
                                Time = N * 0.625 ms
                                Time Range: 2.5 ms to 10.24 s

                                Range: 0x0004 to 0xFFFF
                                Time = N * 0.625 ms
                                Time Range: 2.5 ms to 40.959375 s */
    uint16_t scan_window;/**< Duration of the scan on the primary advertising channel.
                              Range: 0x0004 to 0x4000
                              Time = N * 0.625 ms
                              Time Range: 2.5 ms to 10.24 s

                              Range: 0x0004 to 0xFFFF
                              Time = N * 0.625 ms
                              Time Range: 2.5 ms to 40.959375 s */
    uint16_t conn_interval_min;/**< Minimum value for the connection interval. This shall be less
                                    than or equal to Conn_Interval_Max[i].
                                    Range: 0x0006 to 0x0C80
                                    Time = N * 1.25 ms
                                    Time Range: 7.5 ms to 4 s */
    uint16_t conn_interval_max;/**< Maximum value for the connection interval. This shall be greater
                                    than or equal to Conn_Interval_Max[i].
                                    Range: 0x0006 to 0x0C80
                                    Time = N * 1.25 ms
                                    Time Range: 7.5 ms to 4 s */
    uint16_t conn_latency;/**< Slave latency for the connection in number of connection events.
                               Range: 0x0000 to 0x01F3 */
    uint16_t supv_tout;/**< Supervision timeout for the LE Link.
                            Range: 0x000A to 0x0C80
                            Time = N * 10 ms
                            Time Range: 100 ms to 32 s */
    uint16_t ce_len_min;/**< Informative parameter recommending the minimum length of connection
                             event needed for this LE connection.
                             Range: 0x0000 - 0xFFFF
                             Time = N * 0.625 ms */
    uint16_t ce_len_max;/**< Informative parameter recommending the maximum length of connection
                             event needed for this LE connection.
                             Range: 0x0000 - 0xFFFF
                             Time = N * 0.625 ms */
};

/** @brief Local Device Name */
struct RPC_T_LOCAL_NAME
{
    uint8_t local_name[40];
};

/** @brief Local Device Appearance */
struct RPC_T_LOCAL_APPEARANCE
{
    uint16_t local_appearance;
    uint8_t padding[2];
};

/** @brief Local IRK */
struct RPC_T_LOCAL_IRK
{
    uint8_t local_irk[16];
};

/** @brief Remote Bluetooth device address info */
struct RPC_T_LE_REMOTE_BD
{
    uint8_t addr[6];
    uint8_t remote_bd_type;
    uint8_t bond_flags;
};

/** @brief LE CCCD info */
struct RPC_T_LE_CCCD
{
    uint8_t data_length;
    uint8_t padding[3];
    uint8_t data;
};

/** @brief LE key entry */
struct RPC_T_LE_KEY_ENTRY
{
    bool is_used;
    uint8_t idx;
    uint16_t flags;
    uint8_t local_bd_type;
    uint8_t app_data;
    uint8_t reserved[2];
    RPC_T_LE_REMOTE_BD remote_bd;
    RPC_T_LE_REMOTE_BD resolved_remote_bd;
};


#endif // ERPC_TYPE_DEFINITIONS


#endif // _rpc_system_header_h_
