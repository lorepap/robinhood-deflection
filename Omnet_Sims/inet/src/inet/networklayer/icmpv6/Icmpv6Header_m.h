//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/icmpv6/Icmpv6Header.msg.
//

#ifndef __INET_ICMPV6HEADER_M_H
#define __INET_ICMPV6HEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class Icmpv6Header;
class Icmpv6DestUnreachableMsg;
class Icmpv6PacketTooBigMsg;
class Icmpv6TimeExceededMsg;
class Icmpv6ParamProblemMsg;
class Icmpv6EchoRequestMsg;
class Icmpv6EchoReplyMsg;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/transportlayer/common/CrcMode_m.h" // import inet.transportlayer.common.CrcMode


namespace inet {

// cplusplus {{
const B ICMPv6_HEADER_BYTES = B(8);
// }}

/**
 * Enum generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:36</tt> by opp_msgtool.
 * <pre>
 * enum Icmpv6Type
 * {
 *     ICMPv6_UNSPECIFIED = 0;
 *     ICMPv6_DESTINATION_UNREACHABLE = 1;
 *     ICMPv6_PACKET_TOO_BIG = 2;
 *     ICMPv6_TIME_EXCEEDED = 3;
 *     ICMPv6_PARAMETER_PROBLEM = 4;
 *     ICMPv6_ECHO_REQUEST = 128;
 *     ICMPv6_ECHO_REPLY = 129;
 *     ICMPv6_MLD_QUERY = 130;
 *     ICMPv6_MLD_REPORT = 131;
 *     ICMPv6_MLD_DONE = 132;
 *     ICMPv6_ROUTER_SOL = 133;
 *     ICMPv6_ROUTER_AD = 134;
 *     ICMPv6_NEIGHBOUR_SOL = 135;
 *     ICMPv6_NEIGHBOUR_AD = 136;
 *     ICMPv6_REDIRECT = 137;
 *     ICMPv6_MLDv2_REPORT = 143;
 *     ICMPv6_EXPERIMENTAL_MOBILITY = 150;  //Zarrar Yousaf 02.08.07 (FMIPv6 Implementation)
 * }
 * </pre>
 */
enum Icmpv6Type {
    ICMPv6_UNSPECIFIED = 0,
    ICMPv6_DESTINATION_UNREACHABLE = 1,
    ICMPv6_PACKET_TOO_BIG = 2,
    ICMPv6_TIME_EXCEEDED = 3,
    ICMPv6_PARAMETER_PROBLEM = 4,
    ICMPv6_ECHO_REQUEST = 128,
    ICMPv6_ECHO_REPLY = 129,
    ICMPv6_MLD_QUERY = 130,
    ICMPv6_MLD_REPORT = 131,
    ICMPv6_MLD_DONE = 132,
    ICMPv6_ROUTER_SOL = 133,
    ICMPv6_ROUTER_AD = 134,
    ICMPv6_NEIGHBOUR_SOL = 135,
    ICMPv6_NEIGHBOUR_AD = 136,
    ICMPv6_REDIRECT = 137,
    ICMPv6_MLDv2_REPORT = 143,
    ICMPv6_EXPERIMENTAL_MOBILITY = 150
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6Type& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6Type& e) { int n; b->unpack(n); e = static_cast<Icmpv6Type>(n); }

/**
 * Enum generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:62</tt> by opp_msgtool.
 * <pre>
 * //
 * // ICMPv6 "codes" for type ICMPv6_DESTINATION_UNREACHABLE
 * //
 * enum Icmpv6DestUnav
 * {
 *     NO_ROUTE_TO_DEST = 0;
 *     COMM_WITH_DEST_PROHIBITED = 1;
 *     //2 - NOT ASSIGNED
 *     ADDRESS_UNREACHABLE = 3;
 *     PORT_UNREACHABLE = 4;
 * }
 * </pre>
 */
enum Icmpv6DestUnav {
    NO_ROUTE_TO_DEST = 0,
    COMM_WITH_DEST_PROHIBITED = 1,
    ADDRESS_UNREACHABLE = 3,
    PORT_UNREACHABLE = 4
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6DestUnav& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6DestUnav& e) { int n; b->unpack(n); e = static_cast<Icmpv6DestUnav>(n); }

/**
 * Enum generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:76</tt> by opp_msgtool.
 * <pre>
 * //
 * // ICMPv6 "codes" for type ICMPv6_TIME_EXCEEDED
 * //
 * enum Icmpv6TimeEx
 * {
 *     ND_HOP_LIMIT_EXCEEDED = 0;
 *     ND_FRAGMENT_REASSEMBLY_TIME = 1;
 * }
 * </pre>
 */
enum Icmpv6TimeEx {
    ND_HOP_LIMIT_EXCEEDED = 0,
    ND_FRAGMENT_REASSEMBLY_TIME = 1
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6TimeEx& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6TimeEx& e) { int n; b->unpack(n); e = static_cast<Icmpv6TimeEx>(n); }

/**
 * Enum generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:86</tt> by opp_msgtool.
 * <pre>
 * //
 * // ICMPv6 "codes" for type ICMPv6_PARAMETER_PROBLEM
 * //
 * enum Icmpv6ParameterProblem
 * {
 *     ERROREOUS_HDR_FIELD = 0;
 *     UNRECOGNIZED_NEXT_HDR_TYPE = 1;
 *     UNRECOGNIZED_IPV6_OPTION = 2;
 * }
 * </pre>
 */
enum Icmpv6ParameterProblem {
    ERROREOUS_HDR_FIELD = 0,
    UNRECOGNIZED_NEXT_HDR_TYPE = 1,
    UNRECOGNIZED_IPV6_OPTION = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6ParameterProblem& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6ParameterProblem& e) { int n; b->unpack(n); e = static_cast<Icmpv6ParameterProblem>(n); }

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:104</tt> by opp_msgtool.
 * <pre>
 * //
 * // Represents an ICMPv6 packet.
 * //
 * // Notes:
 * //    1. number of octets excluding the error datagram that is usually appended
 * //       in optInfo, i.e. the Type|CODE|CHECKSUM|UNUSED/POINTER/MTU/OTHER
 * //       as defined in RFC2463
 * //    2. Any ICMP type with MSB set, i.e. >=128 is an Informational ICMP message
 * //
 * class Icmpv6Header extends FieldsChunk
 * {
 *     chunkLength = ICMPv6_HEADER_BYTES;
 *     Icmpv6Type type;     // 1 byte
 *     //int code; // 1 byte //TODO: this should be specific to different ICMP types.
 *     int chksum = 0;     // 2 bytes
 *     CrcMode crcMode = CRC_MODE_UNDEFINED;
 *     // 4 bytes 'type' specific values
 * }
 * </pre>
 */
class INET_API Icmpv6Header : public ::inet::FieldsChunk
{
  protected:
    Icmpv6Type type = static_cast<inet::Icmpv6Type>(-1);
    int chksum = 0;
    CrcMode crcMode = CRC_MODE_UNDEFINED;

  private:
    void copy(const Icmpv6Header& other);

  protected:
    bool operator==(const Icmpv6Header&) = delete;

  public:
    Icmpv6Header();
    Icmpv6Header(const Icmpv6Header& other);
    virtual ~Icmpv6Header();
    Icmpv6Header& operator=(const Icmpv6Header& other);
    virtual Icmpv6Header *dup() const override {return new Icmpv6Header(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual Icmpv6Type getType() const;
    virtual void setType(Icmpv6Type type);

    virtual int getChksum() const;
    virtual void setChksum(int chksum);

    virtual CrcMode getCrcMode() const;
    virtual void setCrcMode(CrcMode crcMode);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6Header& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6Header& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:118</tt> by opp_msgtool.
 * <pre>
 * //
 * // Notes:
 * //   1. As defined in RFC2463: Section 3
 * //
 * class Icmpv6DestUnreachableMsg extends Icmpv6Header
 * {
 *     type = ICMPv6_DESTINATION_UNREACHABLE;
 *     Icmpv6DestUnav code;
 *     // unused 4 bytes
 * }
 * </pre>
 */
class INET_API Icmpv6DestUnreachableMsg : public ::inet::Icmpv6Header
{
  protected:
    Icmpv6DestUnav code = static_cast<inet::Icmpv6DestUnav>(-1);

  private:
    void copy(const Icmpv6DestUnreachableMsg& other);

  protected:
    bool operator==(const Icmpv6DestUnreachableMsg&) = delete;

  public:
    Icmpv6DestUnreachableMsg();
    Icmpv6DestUnreachableMsg(const Icmpv6DestUnreachableMsg& other);
    virtual ~Icmpv6DestUnreachableMsg();
    Icmpv6DestUnreachableMsg& operator=(const Icmpv6DestUnreachableMsg& other);
    virtual Icmpv6DestUnreachableMsg *dup() const override {return new Icmpv6DestUnreachableMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual Icmpv6DestUnav getCode() const;
    virtual void setCode(Icmpv6DestUnav code);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6DestUnreachableMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6DestUnreachableMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:125</tt> by opp_msgtool.
 * <pre>
 * class Icmpv6PacketTooBigMsg extends Icmpv6Header
 * {
 *     type = ICMPv6_PACKET_TOO_BIG;
 *     int code; //Set to 0 by sender and ignored by receiver.
 *     int MTU; //MTU of next-hop link
 * }
 * </pre>
 */
class INET_API Icmpv6PacketTooBigMsg : public ::inet::Icmpv6Header
{
  protected:
    int code = 0;
    int MTU = 0;

  private:
    void copy(const Icmpv6PacketTooBigMsg& other);

  protected:
    bool operator==(const Icmpv6PacketTooBigMsg&) = delete;

  public:
    Icmpv6PacketTooBigMsg();
    Icmpv6PacketTooBigMsg(const Icmpv6PacketTooBigMsg& other);
    virtual ~Icmpv6PacketTooBigMsg();
    Icmpv6PacketTooBigMsg& operator=(const Icmpv6PacketTooBigMsg& other);
    virtual Icmpv6PacketTooBigMsg *dup() const override {return new Icmpv6PacketTooBigMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getCode() const;
    virtual void setCode(int code);

    virtual int getMTU() const;
    virtual void setMTU(int MTU);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6PacketTooBigMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6PacketTooBigMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:132</tt> by opp_msgtool.
 * <pre>
 * class Icmpv6TimeExceededMsg extends Icmpv6Header
 * {
 *     type = ICMPv6_TIME_EXCEEDED;
 *     Icmpv6TimeEx code;
 * }
 * </pre>
 */
class INET_API Icmpv6TimeExceededMsg : public ::inet::Icmpv6Header
{
  protected:
    Icmpv6TimeEx code = static_cast<inet::Icmpv6TimeEx>(-1);

  private:
    void copy(const Icmpv6TimeExceededMsg& other);

  protected:
    bool operator==(const Icmpv6TimeExceededMsg&) = delete;

  public:
    Icmpv6TimeExceededMsg();
    Icmpv6TimeExceededMsg(const Icmpv6TimeExceededMsg& other);
    virtual ~Icmpv6TimeExceededMsg();
    Icmpv6TimeExceededMsg& operator=(const Icmpv6TimeExceededMsg& other);
    virtual Icmpv6TimeExceededMsg *dup() const override {return new Icmpv6TimeExceededMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual Icmpv6TimeEx getCode() const;
    virtual void setCode(Icmpv6TimeEx code);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6TimeExceededMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6TimeExceededMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:138</tt> by opp_msgtool.
 * <pre>
 * class Icmpv6ParamProblemMsg extends Icmpv6Header
 * {
 *     type = ICMPv6_PARAMETER_PROBLEM;
 *     Icmpv6ParameterProblem code;
 * }
 * </pre>
 */
class INET_API Icmpv6ParamProblemMsg : public ::inet::Icmpv6Header
{
  protected:
    Icmpv6ParameterProblem code = static_cast<inet::Icmpv6ParameterProblem>(-1);

  private:
    void copy(const Icmpv6ParamProblemMsg& other);

  protected:
    bool operator==(const Icmpv6ParamProblemMsg&) = delete;

  public:
    Icmpv6ParamProblemMsg();
    Icmpv6ParamProblemMsg(const Icmpv6ParamProblemMsg& other);
    virtual ~Icmpv6ParamProblemMsg();
    Icmpv6ParamProblemMsg& operator=(const Icmpv6ParamProblemMsg& other);
    virtual Icmpv6ParamProblemMsg *dup() const override {return new Icmpv6ParamProblemMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual Icmpv6ParameterProblem getCode() const;
    virtual void setCode(Icmpv6ParameterProblem code);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6ParamProblemMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6ParamProblemMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:148</tt> by opp_msgtool.
 * <pre>
 * //
 * // ICMPv6 Echo Request packet (RFC2463: Section 4).
 * // Data is attached through encapsulation (see Icmpv6.cc)
 * //
 * class Icmpv6EchoRequestMsg extends Icmpv6Header
 * {
 *     type = ICMPv6_ECHO_REQUEST;
 *     int code = 0; //set to 0.
 *     int identifier; // identifier to aid in matching Echo replies. May be Zero
 *     int seqNumber; // sequence number to aid in matching Echo replies. May be Zero
 *         //Data is attached through encapsulation. See Icmpv6.cc
 * }
 * </pre>
 */
class INET_API Icmpv6EchoRequestMsg : public ::inet::Icmpv6Header
{
  protected:
    int code = 0;
    int identifier = 0;
    int seqNumber = 0;

  private:
    void copy(const Icmpv6EchoRequestMsg& other);

  protected:
    bool operator==(const Icmpv6EchoRequestMsg&) = delete;

  public:
    Icmpv6EchoRequestMsg();
    Icmpv6EchoRequestMsg(const Icmpv6EchoRequestMsg& other);
    virtual ~Icmpv6EchoRequestMsg();
    Icmpv6EchoRequestMsg& operator=(const Icmpv6EchoRequestMsg& other);
    virtual Icmpv6EchoRequestMsg *dup() const override {return new Icmpv6EchoRequestMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getCode() const;
    virtual void setCode(int code);

    virtual int getIdentifier() const;
    virtual void setIdentifier(int identifier);

    virtual int getSeqNumber() const;
    virtual void setSeqNumber(int seqNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6EchoRequestMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6EchoRequestMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/icmpv6/Icmpv6Header.msg:160</tt> by opp_msgtool.
 * <pre>
 * //
 * // Icmpv6 Echo Reply packet. Data is attached through encapsulation (see Icmpv6.cc)
 * //
 * class Icmpv6EchoReplyMsg extends Icmpv6Header
 * {
 *     type = ICMPv6_ECHO_REPLY;
 *     int code = 0; //set to 0.
 *     int identifier; // identifier to aid in matching Echo replies. May be Zero
 *     int seqNumber; // sequence number to aid in matching Echo replies. May be Zero
 * }
 * </pre>
 */
class INET_API Icmpv6EchoReplyMsg : public ::inet::Icmpv6Header
{
  protected:
    int code = 0;
    int identifier = 0;
    int seqNumber = 0;

  private:
    void copy(const Icmpv6EchoReplyMsg& other);

  protected:
    bool operator==(const Icmpv6EchoReplyMsg&) = delete;

  public:
    Icmpv6EchoReplyMsg();
    Icmpv6EchoReplyMsg(const Icmpv6EchoReplyMsg& other);
    virtual ~Icmpv6EchoReplyMsg();
    Icmpv6EchoReplyMsg& operator=(const Icmpv6EchoReplyMsg& other);
    virtual Icmpv6EchoReplyMsg *dup() const override {return new Icmpv6EchoReplyMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getCode() const;
    virtual void setCode(int code);

    virtual int getIdentifier() const;
    virtual void setIdentifier(int identifier);

    virtual int getSeqNumber() const;
    virtual void setSeqNumber(int seqNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Icmpv6EchoReplyMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Icmpv6EchoReplyMsg& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::Icmpv6Header *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6Header*>(ptr.get<cObject>()); }
template<> inline inet::Icmpv6DestUnreachableMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6DestUnreachableMsg*>(ptr.get<cObject>()); }
template<> inline inet::Icmpv6PacketTooBigMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6PacketTooBigMsg*>(ptr.get<cObject>()); }
template<> inline inet::Icmpv6TimeExceededMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6TimeExceededMsg*>(ptr.get<cObject>()); }
template<> inline inet::Icmpv6ParamProblemMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6ParamProblemMsg*>(ptr.get<cObject>()); }
template<> inline inet::Icmpv6EchoRequestMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6EchoRequestMsg*>(ptr.get<cObject>()); }
template<> inline inet::Icmpv6EchoReplyMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Icmpv6EchoReplyMsg*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_ICMPV6HEADER_M_H

