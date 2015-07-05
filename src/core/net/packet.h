//
// packet.h
// CawotteSrv
//
// Created by Luax on 6/28/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#ifndef CAWOTTESRV_PACKET_H
#define CAWOTTESRV_PACKET_H

#include "dofus/network/messages/imessage.h"
#include "core/io/binaryreader.h"
#include "core/io/binarywriter.h"

class Packet
{
public:
    Packet();
    ~Packet();

    void serialize(IMessage& message, std::vector<char>& buffer);
    bool deserialize(std::vector<char>& buffer);

    unsigned short id();
    unsigned int length();
    std::vector<char> data();

private:
    unsigned short _header;
    unsigned short _id;
    unsigned short _lengthType;
    unsigned int _length;
    std::vector<char> _data;

    unsigned short getMessageId(unsigned short header);
    unsigned short getMessageLengthType(unsigned short header);
    unsigned int getMessageLength(unsigned short lengthType, BinaryReader& reader);
    unsigned short computeLengthType(unsigned int length);
    unsigned short computeHeader(unsigned short id, unsigned short lengthType);
};

#endif // CAWOTTESRV_PACKET_H
