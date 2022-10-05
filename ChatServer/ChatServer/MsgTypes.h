#ifndef MSGTYPES_H
#define MSGTYPES_H

#endif // MSGTYPES_H

enum ServerMsgType
{
    usr_msg,
    succesful_enter,
    unsuccesful_enter,
    unsuccesful_reg,
    succesful_reg,
    succesful_add,
    unsuccesful_add,
    unsuccesful_create_gc,
    succesful_create_gc,
    req_chat_sending,
    reloaded_contacts
};

enum ClientMsgType
{
    message,
    try_to_log_in,
    try_to_reg,
    try_to_add,
    reload_contacts,
    try_to_create_gc,
    chat_msgs_req,
    direct_msg
};
