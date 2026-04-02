/** @file
 *    @brief MAVLink comm protocol testsuite generated from custom_dog.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef CUSTOM_DOG_TESTSUITE_H
#define CUSTOM_DOG_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_custom_dog(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_custom_dog(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_custom_dog_joy_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_custom_dog_joy_data_t packet_in = {
        17.0,45.0,73.0,101.0
    };
    mavlink_custom_dog_joy_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lx = packet_in.lx;
        packet1.ly = packet_in.ly;
        packet1.rx = packet_in.rx;
        packet1.ry = packet_in.ry;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_joy_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_custom_dog_joy_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_joy_data_pack(system_id, component_id, &msg , packet1.lx , packet1.ly , packet1.rx , packet1.ry );
    mavlink_msg_custom_dog_joy_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_joy_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lx , packet1.ly , packet1.rx , packet1.ry );
    mavlink_msg_custom_dog_joy_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_custom_dog_joy_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_joy_data_send(MAVLINK_COMM_1 , packet1.lx , packet1.ly , packet1.rx , packet1.ry );
    mavlink_msg_custom_dog_joy_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CUSTOM_DOG_JOY_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA) != NULL);
#endif
}

static void mavlink_test_custom_dog_support_ability(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_custom_dog_support_ability_t packet_in = {
        963497464
    };
    mavlink_custom_dog_support_ability_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.capability_bitmask = packet_in.capability_bitmask;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_support_ability_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_custom_dog_support_ability_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_support_ability_pack(system_id, component_id, &msg , packet1.capability_bitmask );
    mavlink_msg_custom_dog_support_ability_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_support_ability_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.capability_bitmask );
    mavlink_msg_custom_dog_support_ability_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_custom_dog_support_ability_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_support_ability_send(MAVLINK_COMM_1 , packet1.capability_bitmask );
    mavlink_msg_custom_dog_support_ability_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CUSTOM_DOG_SUPPORT_ABILITY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY) != NULL);
#endif
}

static void mavlink_test_custom_dog_current_available_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_custom_dog_current_available_cmd_t packet_in = {
        963497464
    };
    mavlink_custom_dog_current_available_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.available_cmd_bitmask = packet_in.available_cmd_bitmask;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_current_available_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_custom_dog_current_available_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_current_available_cmd_pack(system_id, component_id, &msg , packet1.available_cmd_bitmask );
    mavlink_msg_custom_dog_current_available_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_current_available_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.available_cmd_bitmask );
    mavlink_msg_custom_dog_current_available_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_custom_dog_current_available_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_current_available_cmd_send(MAVLINK_COMM_1 , packet1.available_cmd_bitmask );
    mavlink_msg_custom_dog_current_available_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CUSTOM_DOG_CURRENT_AVAILABLE_CMD") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD) != NULL);
#endif
}

static void mavlink_test_custom_dog_battery_level(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_custom_dog_battery_level_t packet_in = {
        963497464
    };
    mavlink_custom_dog_battery_level_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.battery_level = packet_in.battery_level;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_battery_level_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_custom_dog_battery_level_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_battery_level_pack(system_id, component_id, &msg , packet1.battery_level );
    mavlink_msg_custom_dog_battery_level_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_battery_level_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.battery_level );
    mavlink_msg_custom_dog_battery_level_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_custom_dog_battery_level_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_custom_dog_battery_level_send(MAVLINK_COMM_1 , packet1.battery_level );
    mavlink_msg_custom_dog_battery_level_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CUSTOM_DOG_BATTERY_LEVEL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL) != NULL);
#endif
}

static void mavlink_test_custom_dog(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_custom_dog_joy_data(system_id, component_id, last_msg);
    mavlink_test_custom_dog_support_ability(system_id, component_id, last_msg);
    mavlink_test_custom_dog_current_available_cmd(system_id, component_id, last_msg);
    mavlink_test_custom_dog_battery_level(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // CUSTOM_DOG_TESTSUITE_H
