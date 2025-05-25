/** @file
 *	@brief MAVLink comm testsuite protocol generated from elevator.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "elevator.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(elevator, ELEVATOR_INFORMATION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::elevator::msg::ELEVATOR_INFORMATION packet_in{};
    packet_in.gimbal_id = 5;

    mavlink::elevator::msg::ELEVATOR_INFORMATION packet1{};
    mavlink::elevator::msg::ELEVATOR_INFORMATION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.gimbal_id, packet2.gimbal_id);
}

#ifdef TEST_INTEROP
TEST(elevator_interop, ELEVATOR_INFORMATION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_elevator_information_t packet_c {
         5
    };

    mavlink::elevator::msg::ELEVATOR_INFORMATION packet_in{};
    packet_in.gimbal_id = 5;

    mavlink::elevator::msg::ELEVATOR_INFORMATION packet2{};

    mavlink_msg_elevator_information_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.gimbal_id, packet2.gimbal_id);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
