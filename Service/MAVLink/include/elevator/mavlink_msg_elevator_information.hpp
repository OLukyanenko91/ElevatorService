// MESSAGE ELEVATOR_INFORMATION support class

#pragma once

namespace mavlink {
namespace elevator {
namespace msg {

/**
 * @brief ELEVATOR_INFORMATION message
 *
 * Some description.
 */
struct ELEVATOR_INFORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60010;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 33;
    static constexpr auto NAME = "ELEVATOR_INFORMATION";


    uint8_t gimbal_id; /*<  Description. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  gimbal_id: " << +gimbal_id << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << gimbal_id;                     // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> gimbal_id;                     // offset: 0
    }
};

} // namespace msg
} // namespace elevator
} // namespace mavlink
