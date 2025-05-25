#pragma once
// MESSAGE ELEVATOR_INFORMATION PACKING

#define MAVLINK_MSG_ID_ELEVATOR_INFORMATION 60010


typedef struct __mavlink_elevator_information_t {
 uint8_t gimbal_id; /*<  Description.*/
} mavlink_elevator_information_t;

#define MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN 1
#define MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN 1
#define MAVLINK_MSG_ID_60010_LEN 1
#define MAVLINK_MSG_ID_60010_MIN_LEN 1

#define MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC 33
#define MAVLINK_MSG_ID_60010_CRC 33



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ELEVATOR_INFORMATION { \
    60010, \
    "ELEVATOR_INFORMATION", \
    1, \
    {  { "gimbal_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_elevator_information_t, gimbal_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ELEVATOR_INFORMATION { \
    "ELEVATOR_INFORMATION", \
    1, \
    {  { "gimbal_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_elevator_information_t, gimbal_id) }, \
         } \
}
#endif

/**
 * @brief Pack a elevator_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gimbal_id  Description.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_elevator_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t gimbal_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 0, gimbal_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#else
    mavlink_elevator_information_t packet;
    packet.gimbal_id = gimbal_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELEVATOR_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
}

/**
 * @brief Pack a elevator_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param gimbal_id  Description.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_elevator_information_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t gimbal_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 0, gimbal_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#else
    mavlink_elevator_information_t packet;
    packet.gimbal_id = gimbal_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELEVATOR_INFORMATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#endif
}

/**
 * @brief Pack a elevator_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_id  Description.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_elevator_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t gimbal_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 0, gimbal_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#else
    mavlink_elevator_information_t packet;
    packet.gimbal_id = gimbal_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELEVATOR_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
}

/**
 * @brief Encode a elevator_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param elevator_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_elevator_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_elevator_information_t* elevator_information)
{
    return mavlink_msg_elevator_information_pack(system_id, component_id, msg, elevator_information->gimbal_id);
}

/**
 * @brief Encode a elevator_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param elevator_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_elevator_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_elevator_information_t* elevator_information)
{
    return mavlink_msg_elevator_information_pack_chan(system_id, component_id, chan, msg, elevator_information->gimbal_id);
}

/**
 * @brief Encode a elevator_information struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param elevator_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_elevator_information_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_elevator_information_t* elevator_information)
{
    return mavlink_msg_elevator_information_pack_status(system_id, component_id, _status, msg,  elevator_information->gimbal_id);
}

/**
 * @brief Send a elevator_information message
 * @param chan MAVLink channel to send the message
 *
 * @param gimbal_id  Description.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_elevator_information_send(mavlink_channel_t chan, uint8_t gimbal_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 0, gimbal_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELEVATOR_INFORMATION, buf, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
#else
    mavlink_elevator_information_t packet;
    packet.gimbal_id = gimbal_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELEVATOR_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a elevator_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_elevator_information_send_struct(mavlink_channel_t chan, const mavlink_elevator_information_t* elevator_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_elevator_information_send(chan, elevator_information->gimbal_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELEVATOR_INFORMATION, (const char *)elevator_information, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_elevator_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t gimbal_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, gimbal_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELEVATOR_INFORMATION, buf, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
#else
    mavlink_elevator_information_t *packet = (mavlink_elevator_information_t *)msgbuf;
    packet->gimbal_id = gimbal_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELEVATOR_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE ELEVATOR_INFORMATION UNPACKING


/**
 * @brief Get field gimbal_id from elevator_information message
 *
 * @return  Description.
 */
static inline uint8_t mavlink_msg_elevator_information_get_gimbal_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a elevator_information message into a struct
 *
 * @param msg The message to decode
 * @param elevator_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_elevator_information_decode(const mavlink_message_t* msg, mavlink_elevator_information_t* elevator_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    elevator_information->gimbal_id = mavlink_msg_elevator_information_get_gimbal_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN;
        memset(elevator_information, 0, MAVLINK_MSG_ID_ELEVATOR_INFORMATION_LEN);
    memcpy(elevator_information, _MAV_PAYLOAD(msg), len);
#endif
}
