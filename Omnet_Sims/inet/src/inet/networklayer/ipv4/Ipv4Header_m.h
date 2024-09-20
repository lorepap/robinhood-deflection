//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/ipv4/Ipv4Header.msg.
//

#ifndef __INET_IPV4HEADER_M_H
#define __INET_IPV4HEADER_M_H

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

class Ipv4Option;
class Ipv4OptionNop;
class Ipv4OptionEnd;
class Ipv4OptionRecordRoute;
class Ipv4OptionTimestamp;
class Ipv4OptionStreamId;
class Ipv4OptionRouterAlert;
class Ipv4OptionUnknown;
class Ipv4OptionV2Marking;
class Ipv4OptionSwift;
class Ipv4Header;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TlvOptions_m.h" // import inet.common.TlvOptions

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/common/IpProtocolId_m.h" // import inet.networklayer.common.IpProtocolId

#include "inet/networklayer/contract/NetworkHeaderBase_m.h" // import inet.networklayer.contract.NetworkHeaderBase

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

#include "inet/transportlayer/common/CrcMode_m.h" // import inet.transportlayer.common.CrcMode

// cplusplus {{
#include "inet/common/ProtocolGroup.h"
// }}


namespace inet {

// cplusplus {{
// default Ipv4 header length: 20 bytes
const B IPv4_MIN_HEADER_LENGTH = B(20);

// maximum Ipv4 header length (base+options): 60 = 4 * 15 bytes
const B IPv4_MAX_HEADER_LENGTH = B(60);

// option type fields
const unsigned char IPOPTION_COPY_MASK   = 0x80;
const unsigned char IPOPTION_CLASS_MASK  = 0x60;
const unsigned char IPOPTION_NUMBER_MASK = 0x1F;

// option entry number
const unsigned int MAX_IPADDR_OPTION_ENTRIES = 9;
const unsigned int MAX_TIMESTAMP_OPTION_ENTRIES = 4;
// }}

/**
 * Enum generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:57</tt> by opp_msgtool.
 * <pre>
 * //
 * // Ipv4 options class
 * //
 * enum Ipv4OptionClass
 * {
 *     IPOPTION_CLASS_CONTROL = 0;
 *     IPOPTION_CLASS_RESERVED = 1;
 *     IPOPTION_CLASS_DEBUGGING = 2;
 *     IPOPTION_CLASS_RESERVED2 = 3;
 * }
 * </pre>
 */
enum Ipv4OptionClass {
    IPOPTION_CLASS_CONTROL = 0,
    IPOPTION_CLASS_RESERVED = 1,
    IPOPTION_CLASS_DEBUGGING = 2,
    IPOPTION_CLASS_RESERVED2 = 3
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionClass& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionClass& e) { int n; b->unpack(n); e = static_cast<Ipv4OptionClass>(n); }

/**
 * Enum generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:68</tt> by opp_msgtool.
 * <pre>
 * //
 * // Ipv4 option types
 * //
 * enum Ipv4OptionType
 * {
 *     IPOPTION_END_OF_OPTIONS = 0;
 *     IPOPTION_NO_OPTION = 1;
 *     IPOPTION_STREAM_ID = 136;
 * 
 *     IPOPTION_TIMESTAMP = 68;
 * 
 *     IPOPTION_SECURITY = 130;
 *     IPOPTION_LOOSE_SOURCE_ROUTING = 131;
 *     IPOPTION_RECORD_ROUTE = 7;
 *     IPOPTION_STRICT_SOURCE_ROUTING = 137;
 *     IPOPTION_ROUTER_ALERT = 148;
 * 
 *     IPOPTION_TLV_GPSR = 47;
 * 
 *     // v2 marking component
 *     IPOPTION_V2_MARKING = 1375;
 * 
 *     // swift header overhead
 *     IP_SWIFT_OVERHEAD = 1376;
 * }
 * </pre>
 */
enum Ipv4OptionType {
    IPOPTION_END_OF_OPTIONS = 0,
    IPOPTION_NO_OPTION = 1,
    IPOPTION_STREAM_ID = 136,
    IPOPTION_TIMESTAMP = 68,
    IPOPTION_SECURITY = 130,
    IPOPTION_LOOSE_SOURCE_ROUTING = 131,
    IPOPTION_RECORD_ROUTE = 7,
    IPOPTION_STRICT_SOURCE_ROUTING = 137,
    IPOPTION_ROUTER_ALERT = 148,
    IPOPTION_TLV_GPSR = 47,
    IPOPTION_V2_MARKING = 1375,
    IP_SWIFT_OVERHEAD = 1376
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionType& e) { int n; b->unpack(n); e = static_cast<Ipv4OptionType>(n); }

/**
 * Enum generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:94</tt> by opp_msgtool.
 * <pre>
 * //
 * // The timestamp flag uses the same numeric values as the Ipv4 Protocol
 * //
 * enum TimestampFlag
 * {
 *     IP_TIMESTAMP_TIMESTAMP_ONLY = 0;
 *     IP_TIMESTAMP_WITH_ADDRESS = 1;
 *     IP_TIMESTAMP_SENDER_INIT_ADDRESS = 3;
 * }
 * </pre>
 */
enum TimestampFlag {
    IP_TIMESTAMP_TIMESTAMP_ONLY = 0,
    IP_TIMESTAMP_WITH_ADDRESS = 1,
    IP_TIMESTAMP_SENDER_INIT_ADDRESS = 3
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TimestampFlag& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TimestampFlag& e) { int n; b->unpack(n); e = static_cast<TimestampFlag>(n); }

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:101</tt> by opp_msgtool.
 * <pre>
 * class Ipv4Option extends TlvOptionBase
 * {
 * }
 * </pre>
 */
class INET_API Ipv4Option : public ::inet::TlvOptionBase
{
  protected:

  private:
    void copy(const Ipv4Option& other);

  protected:
    bool operator==(const Ipv4Option&) = delete;

  public:
    Ipv4Option();
    Ipv4Option(const Ipv4Option& other);
    virtual ~Ipv4Option();
    Ipv4Option& operator=(const Ipv4Option& other);
    virtual Ipv4Option *dup() const override {return new Ipv4Option(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4Option& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4Option& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:105</tt> by opp_msgtool.
 * <pre>
 * class Ipv4OptionNop extends Ipv4Option
 * {
 *     type = IPOPTION_NO_OPTION;
 *     length = 1;
 * }
 * </pre>
 */
class INET_API Ipv4OptionNop : public ::inet::Ipv4Option
{
  protected:

  private:
    void copy(const Ipv4OptionNop& other);

  protected:
    bool operator==(const Ipv4OptionNop&) = delete;

  public:
    Ipv4OptionNop();
    Ipv4OptionNop(const Ipv4OptionNop& other);
    virtual ~Ipv4OptionNop();
    Ipv4OptionNop& operator=(const Ipv4OptionNop& other);
    virtual Ipv4OptionNop *dup() const override {return new Ipv4OptionNop(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionNop& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionNop& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:111</tt> by opp_msgtool.
 * <pre>
 * class Ipv4OptionEnd extends Ipv4Option
 * {
 *     type = IPOPTION_END_OF_OPTIONS;
 *     length = 1;
 * }
 * </pre>
 */
class INET_API Ipv4OptionEnd : public ::inet::Ipv4Option
{
  protected:

  private:
    void copy(const Ipv4OptionEnd& other);

  protected:
    bool operator==(const Ipv4OptionEnd&) = delete;

  public:
    Ipv4OptionEnd();
    Ipv4OptionEnd(const Ipv4OptionEnd& other);
    virtual ~Ipv4OptionEnd();
    Ipv4OptionEnd& operator=(const Ipv4OptionEnd& other);
    virtual Ipv4OptionEnd *dup() const override {return new Ipv4OptionEnd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionEnd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionEnd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:120</tt> by opp_msgtool.
 * <pre>
 * //
 * // Option structure: Record Route
 * //
 * class Ipv4OptionRecordRoute extends Ipv4Option
 * {
 *     // type = IPOPTION_RECORD_ROUTE;
 *     // type = IPOPTION_LOOSE_SOURCE_ROUTING
 *     // type = IPOPTION_STRICT_SOURCE_ROUTING
 *     // length = 3 + 4 * getRecordAddressArraySize();
 *     short nextAddressIdx;
 *     // pointer = 4 + 4 * nextAddressIdx
 *     Ipv4Address recordAddress[];    // max size is 9
 * }
 * </pre>
 */
class INET_API Ipv4OptionRecordRoute : public ::inet::Ipv4Option
{
  protected:
    short nextAddressIdx = 0;
    Ipv4Address *recordAddress = nullptr;
    size_t recordAddress_arraysize = 0;

  private:
    void copy(const Ipv4OptionRecordRoute& other);

  protected:
    bool operator==(const Ipv4OptionRecordRoute&) = delete;

  public:
    Ipv4OptionRecordRoute();
    Ipv4OptionRecordRoute(const Ipv4OptionRecordRoute& other);
    virtual ~Ipv4OptionRecordRoute();
    Ipv4OptionRecordRoute& operator=(const Ipv4OptionRecordRoute& other);
    virtual Ipv4OptionRecordRoute *dup() const override {return new Ipv4OptionRecordRoute(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual short getNextAddressIdx() const;
    virtual void setNextAddressIdx(short nextAddressIdx);

    virtual void setRecordAddressArraySize(size_t size);
    virtual size_t getRecordAddressArraySize() const;
    virtual const Ipv4Address& getRecordAddress(size_t k) const;
    virtual Ipv4Address& getRecordAddressForUpdate(size_t k) { return const_cast<Ipv4Address&>(const_cast<Ipv4OptionRecordRoute*>(this)->getRecordAddress(k));}
    virtual void setRecordAddress(size_t k, const Ipv4Address& recordAddress);
    virtual void insertRecordAddress(size_t k, const Ipv4Address& recordAddress);
    [[deprecated]] void insertRecordAddress(const Ipv4Address& recordAddress) {appendRecordAddress(recordAddress);}
    virtual void appendRecordAddress(const Ipv4Address& recordAddress);
    virtual void eraseRecordAddress(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionRecordRoute& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionRecordRoute& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:134</tt> by opp_msgtool.
 * <pre>
 * //
 * // Option structure: Timestamp
 * //
 * class Ipv4OptionTimestamp extends Ipv4Option
 * {
 *     type = IPOPTION_TIMESTAMP;
 *     // length = 4 + 4 * getRecordAddressArraySize() + 4 * getRecordTimestampArraySize();
 *     TimestampFlag flag;
 *     short overflow;
 *     short nextIdx;
 *     // pointer = 5 + (flag == IP_TIMESTAMP_TIMESTAMP_ONLY ? 4 : 8) * nextIdx
 * 
 *     // use either up to 4 addresses with timestamps or
 *     // only up to 9 timestamps, according to the flag
 *     Ipv4Address recordAddress[];
 *     simtime_t recordTimestamp[];
 * }
 * </pre>
 */
class INET_API Ipv4OptionTimestamp : public ::inet::Ipv4Option
{
  protected:
    TimestampFlag flag = static_cast<inet::TimestampFlag>(-1);
    short overflow = 0;
    short nextIdx = 0;
    Ipv4Address *recordAddress = nullptr;
    size_t recordAddress_arraysize = 0;
    ::omnetpp::simtime_t *recordTimestamp = nullptr;
    size_t recordTimestamp_arraysize = 0;

  private:
    void copy(const Ipv4OptionTimestamp& other);

  protected:
    bool operator==(const Ipv4OptionTimestamp&) = delete;

  public:
    Ipv4OptionTimestamp();
    Ipv4OptionTimestamp(const Ipv4OptionTimestamp& other);
    virtual ~Ipv4OptionTimestamp();
    Ipv4OptionTimestamp& operator=(const Ipv4OptionTimestamp& other);
    virtual Ipv4OptionTimestamp *dup() const override {return new Ipv4OptionTimestamp(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual TimestampFlag getFlag() const;
    virtual void setFlag(TimestampFlag flag);

    virtual short getOverflow() const;
    virtual void setOverflow(short overflow);

    virtual short getNextIdx() const;
    virtual void setNextIdx(short nextIdx);

    virtual void setRecordAddressArraySize(size_t size);
    virtual size_t getRecordAddressArraySize() const;
    virtual const Ipv4Address& getRecordAddress(size_t k) const;
    virtual Ipv4Address& getRecordAddressForUpdate(size_t k) { return const_cast<Ipv4Address&>(const_cast<Ipv4OptionTimestamp*>(this)->getRecordAddress(k));}
    virtual void setRecordAddress(size_t k, const Ipv4Address& recordAddress);
    virtual void insertRecordAddress(size_t k, const Ipv4Address& recordAddress);
    [[deprecated]] void insertRecordAddress(const Ipv4Address& recordAddress) {appendRecordAddress(recordAddress);}
    virtual void appendRecordAddress(const Ipv4Address& recordAddress);
    virtual void eraseRecordAddress(size_t k);

    virtual void setRecordTimestampArraySize(size_t size);
    virtual size_t getRecordTimestampArraySize() const;
    virtual ::omnetpp::simtime_t getRecordTimestamp(size_t k) const;
    virtual void setRecordTimestamp(size_t k, ::omnetpp::simtime_t recordTimestamp);
    virtual void insertRecordTimestamp(size_t k, ::omnetpp::simtime_t recordTimestamp);
    [[deprecated]] void insertRecordTimestamp(::omnetpp::simtime_t recordTimestamp) {appendRecordTimestamp(recordTimestamp);}
    virtual void appendRecordTimestamp(::omnetpp::simtime_t recordTimestamp);
    virtual void eraseRecordTimestamp(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionTimestamp& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionTimestamp& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:152</tt> by opp_msgtool.
 * <pre>
 * //
 * // Option Structure: Stream ID
 * //
 * class Ipv4OptionStreamId extends Ipv4Option
 * {
 *     type = IPOPTION_STREAM_ID;
 *     length = 4;
 *     short streamId;
 * }
 * </pre>
 */
class INET_API Ipv4OptionStreamId : public ::inet::Ipv4Option
{
  protected:
    short streamId = 0;

  private:
    void copy(const Ipv4OptionStreamId& other);

  protected:
    bool operator==(const Ipv4OptionStreamId&) = delete;

  public:
    Ipv4OptionStreamId();
    Ipv4OptionStreamId(const Ipv4OptionStreamId& other);
    virtual ~Ipv4OptionStreamId();
    Ipv4OptionStreamId& operator=(const Ipv4OptionStreamId& other);
    virtual Ipv4OptionStreamId *dup() const override {return new Ipv4OptionStreamId(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual short getStreamId() const;
    virtual void setStreamId(short streamId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionStreamId& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionStreamId& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:162</tt> by opp_msgtool.
 * <pre>
 * //
 * // Option Structure: Stream ID
 * //
 * class Ipv4OptionRouterAlert extends Ipv4Option
 * {
 *     type = IPOPTION_ROUTER_ALERT;
 *     length = 4;
 *     uint16_t routerAlert = 0;
 * }
 * </pre>
 */
class INET_API Ipv4OptionRouterAlert : public ::inet::Ipv4Option
{
  protected:
    uint16_t routerAlert = 0;

  private:
    void copy(const Ipv4OptionRouterAlert& other);

  protected:
    bool operator==(const Ipv4OptionRouterAlert&) = delete;

  public:
    Ipv4OptionRouterAlert();
    Ipv4OptionRouterAlert(const Ipv4OptionRouterAlert& other);
    virtual ~Ipv4OptionRouterAlert();
    Ipv4OptionRouterAlert& operator=(const Ipv4OptionRouterAlert& other);
    virtual Ipv4OptionRouterAlert *dup() const override {return new Ipv4OptionRouterAlert(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint16_t getRouterAlert() const;
    virtual void setRouterAlert(uint16_t routerAlert);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionRouterAlert& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionRouterAlert& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:169</tt> by opp_msgtool.
 * <pre>
 * class Ipv4OptionUnknown extends Ipv4Option
 * {
 *     // type = any
 *     // length = 2 + getBytesArraySize()
 *     uint8_t bytes[];
 * }
 * </pre>
 */
class INET_API Ipv4OptionUnknown : public ::inet::Ipv4Option
{
  protected:
    uint8_t *bytes = nullptr;
    size_t bytes_arraysize = 0;

  private:
    void copy(const Ipv4OptionUnknown& other);

  protected:
    bool operator==(const Ipv4OptionUnknown&) = delete;

  public:
    Ipv4OptionUnknown();
    Ipv4OptionUnknown(const Ipv4OptionUnknown& other);
    virtual ~Ipv4OptionUnknown();
    Ipv4OptionUnknown& operator=(const Ipv4OptionUnknown& other);
    virtual Ipv4OptionUnknown *dup() const override {return new Ipv4OptionUnknown(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual void setBytesArraySize(size_t size);
    virtual size_t getBytesArraySize() const;
    virtual uint8_t getBytes(size_t k) const;
    virtual void setBytes(size_t k, uint8_t bytes);
    virtual void insertBytes(size_t k, uint8_t bytes);
    [[deprecated]] void insertBytes(uint8_t bytes) {appendBytes(bytes);}
    virtual void appendBytes(uint8_t bytes);
    virtual void eraseBytes(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionUnknown& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionUnknown& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:177</tt> by opp_msgtool.
 * <pre>
 * // v2 marking component
 * class Ipv4OptionV2Marking extends Ipv4Option
 * {
 *     type = IPOPTION_V2_MARKING;
 *     length = 8;
 *     int flow_let_id = -1;
 *     unsigned long seq = 0;
 *     unsigned long ret_num = 0;
 *     bool is_first_packet = false;
 *     bool is_control_message = false;
 * }
 * </pre>
 */
class INET_API Ipv4OptionV2Marking : public ::inet::Ipv4Option
{
  protected:
    int flow_let_id = -1;
    unsigned long seq = 0;
    unsigned long ret_num = 0;
    bool is_first_packet = false;
    bool is_control_message = false;

  private:
    void copy(const Ipv4OptionV2Marking& other);

  protected:
    bool operator==(const Ipv4OptionV2Marking&) = delete;

  public:
    Ipv4OptionV2Marking();
    Ipv4OptionV2Marking(const Ipv4OptionV2Marking& other);
    virtual ~Ipv4OptionV2Marking();
    Ipv4OptionV2Marking& operator=(const Ipv4OptionV2Marking& other);
    virtual Ipv4OptionV2Marking *dup() const override {return new Ipv4OptionV2Marking(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getFlow_let_id() const;
    virtual void setFlow_let_id(int flow_let_id);

    virtual unsigned long getSeq() const;
    virtual void setSeq(unsigned long seq);

    virtual unsigned long getRet_num() const;
    virtual void setRet_num(unsigned long ret_num);

    virtual bool getIs_first_packet() const;
    virtual void setIs_first_packet(bool is_first_packet);

    virtual bool getIs_control_message() const;
    virtual void setIs_control_message(bool is_control_message);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionV2Marking& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionV2Marking& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:191</tt> by opp_msgtool.
 * <pre>
 * // swift's header overhead
 * // 4 bytes for remote queueing and 1 byte for hop-count
 * // NIC Rx timestamp is appended locally, no in-net overhead
 * class Ipv4OptionSwift extends Ipv4Option
 * {
 *     type = IP_SWIFT_OVERHEAD;
 *     length = 5;
 * }
 * </pre>
 */
class INET_API Ipv4OptionSwift : public ::inet::Ipv4Option
{
  protected:

  private:
    void copy(const Ipv4OptionSwift& other);

  protected:
    bool operator==(const Ipv4OptionSwift&) = delete;

  public:
    Ipv4OptionSwift();
    Ipv4OptionSwift(const Ipv4OptionSwift& other);
    virtual ~Ipv4OptionSwift();
    Ipv4OptionSwift& operator=(const Ipv4OptionSwift& other);
    virtual Ipv4OptionSwift *dup() const override {return new Ipv4OptionSwift(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4OptionSwift& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4OptionSwift& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/Ipv4Header.msg:211</tt> by opp_msgtool.
 * <pre>
 * //
 * // Represents an Ipv4 datagram.
 * //
 * // Uses the following cPacket fields:
 * //    - getByteLength() / setByteLength() to represent total datagram length
 * //    - hasBitError() / setBitError() to represent datagram correctness
 * //    - getTimestamp() / setTimestamp (simtime) used in timestamp option
 * //
 * // Additional length fields defined in this class are in bytes.
 * //
 * // Only one of the option fields can exist at a time.
 * //
 * // TODO: cleanup order of fields
 * class Ipv4Header extends NetworkHeaderBase
 * {
 *     chunkLength = IPv4_MIN_HEADER_LENGTH;
 * 
 *     short version = 4;      // \@bit(4)
 *     B headerLength = IPv4_MIN_HEADER_LENGTH;         // \@bit(4), bytes, must be multiple of 4
 *     short diffServCodePoint;  // \@bit(6), maps to bits 0-5 of ToS
 *     short typeOfService = 0;
 *     // short __ecn \@custom \@getter(getEcn) \@setter(setEcn);  // \@bit(2),  maps to bits 6-7 of ToS, stored in typeOfService
 *     //    short explicitCongestionNotification;  // \@bit(2),  maps to bits 6-7 of ToS
 *     B totalLengthField;    // \@byte(2)
 * 
 *     uint16_t identification;    // \@byte(2)
 *     bool reservedBit = false;    // \@bit(1)
 *     bool moreFragments;    // \@bit(1)
 *     bool dontFragment;    // \@bit(1)
 *     uint16_t fragmentOffset;         // \@bit(13), must be multiple of 8
 * 
 *     short timeToLive;    // \@byte(1)
 *     IpProtocolId protocolId = IP_PROT_NONE;    // \@byte(1)
 *     uint16_t crc = 0;    // \@byte(2)
 *     CrcMode crcMode = CRC_MODE_UNDEFINED;
 * 
 *     Ipv4Address srcAddress;
 * 
 *     Ipv4Address destAddress;
 * 
 *     TlvOptions options; // array of option pointers, option pointers owned by datagram
 * 
 * }
 * </pre>
 */
class INET_API Ipv4Header : public ::inet::NetworkHeaderBase
{
  protected:
    short version = 4;
    B headerLength = IPv4_MIN_HEADER_LENGTH;
    short diffServCodePoint = 0;
    short typeOfService = 0;
    B totalLengthField = B(-1);
    uint16_t identification = 0;
    bool reservedBit = false;
    bool moreFragments = false;
    bool dontFragment = false;
    uint16_t fragmentOffset = 0;
    short timeToLive = 0;
    IpProtocolId protocolId = IP_PROT_NONE;
    uint16_t crc = 0;
    CrcMode crcMode = CRC_MODE_UNDEFINED;
    Ipv4Address srcAddress;
    Ipv4Address destAddress;
    TlvOptions options;

  private:
    void copy(const Ipv4Header& other);

  protected:
    bool operator==(const Ipv4Header&) = delete;

  public:
    Ipv4Header();
    Ipv4Header(const Ipv4Header& other);
    virtual ~Ipv4Header();
    Ipv4Header& operator=(const Ipv4Header& other);
    virtual Ipv4Header *dup() const override {return new Ipv4Header(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual short getVersion() const;
    virtual void setVersion(short version);

    virtual B getHeaderLength() const;
    virtual void setHeaderLength(B headerLength);

    virtual short getDiffServCodePoint() const;
    virtual void setDiffServCodePoint(short diffServCodePoint);

    virtual short getTypeOfService() const;
    virtual void setTypeOfService(short typeOfService);

    virtual B getTotalLengthField() const;
    virtual void setTotalLengthField(B totalLengthField);

    virtual uint16_t getIdentification() const;
    virtual void setIdentification(uint16_t identification);

    virtual bool getReservedBit() const;
    virtual void setReservedBit(bool reservedBit);

    virtual bool getMoreFragments() const;
    virtual void setMoreFragments(bool moreFragments);

    virtual bool getDontFragment() const;
    virtual void setDontFragment(bool dontFragment);

    virtual uint16_t getFragmentOffset() const;
    virtual void setFragmentOffset(uint16_t fragmentOffset);

    virtual short getTimeToLive() const;
    virtual void setTimeToLive(short timeToLive);

    virtual IpProtocolId getProtocolId() const;
    virtual void setProtocolId(IpProtocolId protocolId);

    virtual uint16_t getCrc() const;
    virtual void setCrc(uint16_t crc);

    virtual CrcMode getCrcMode() const;
    virtual void setCrcMode(CrcMode crcMode);

    virtual const Ipv4Address& getSrcAddress() const;
    virtual Ipv4Address& getSrcAddressForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<Ipv4Header*>(this)->getSrcAddress());}
    virtual void setSrcAddress(const Ipv4Address& srcAddress);

    virtual const Ipv4Address& getDestAddress() const;
    virtual Ipv4Address& getDestAddressForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<Ipv4Header*>(this)->getDestAddress());}
    virtual void setDestAddress(const Ipv4Address& destAddress);

    virtual const TlvOptions& getOptions() const;
    virtual TlvOptions& getOptionsForUpdate() { handleChange();return const_cast<TlvOptions&>(const_cast<Ipv4Header*>(this)->getOptions());}
    virtual void setOptions(const TlvOptions& options);


  public:
    virtual short getEcn() const;
    virtual void setEcn(short ecn);

    /**
     * Returns the number of extension headers in this datagram
     */
    virtual unsigned int getOptionArraySize() const { return options.getTlvOptionArraySize(); }

    /**
     * Returns the kth extension header in this datagram
     */
    virtual TlvOptionBase& getOptionForUpdate(unsigned int k) { handleChange(); return *check_and_cast<TlvOptionBase *>((options.getTlvOptionForUpdate(k))); }
    virtual const TlvOptionBase& getOption(unsigned int k) const { return *check_and_cast<const TlvOptionBase *>((options.getTlvOption(k))); }

    /**
     * Returns the TlvOptionBase of the specified type,
     * or nullptr. If index is 0, then the first, if 1 then the
     * second option is returned.
     */
    virtual TlvOptionBase *findMutableOptionByType(short int optionType, int index = 0);
    virtual const TlvOptionBase *findOptionByType(short int optionType, int index = 0) const;

    /**
     * Adds an TlvOptionBase to the datagram.
     */
    virtual void addOption(TlvOptionBase *opt);
    virtual void addOption(TlvOptionBase *opt, int atPos);

    /**
     * Calculates the length of the Ipv6 header plus the extension
     * headers.
     */
    virtual B calculateHeaderByteLength() const;

    // implements NetworkHeaderBase:
    virtual L3Address getSourceAddress() const override { return L3Address(getSrcAddress()); }
    virtual void setSourceAddress(const L3Address& address) override { setSrcAddress(address.toIpv4()); }
    virtual L3Address getDestinationAddress() const override { return L3Address(getDestAddress()); }
    virtual void setDestinationAddress(const L3Address& address) override { setDestAddress(address.toIpv4()); }
    virtual const Protocol *getProtocol() const override { return ProtocolGroup::ipprotocol.findProtocol(getProtocolId()); }
    virtual void setProtocol(const Protocol *protocol) override { setProtocolId(static_cast<IpProtocolId>(ProtocolGroup::ipprotocol.getProtocolNumber(protocol))); }
    virtual bool isFragment() const override { return getMoreFragments() || (getFragmentOffset() != 0); }

	virtual short getDscp() const;
    virtual void setDscp(short typeOfService);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv4Header& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv4Header& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::Ipv4Option *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4Option*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionNop *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionNop*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionEnd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionEnd*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionRecordRoute *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionRecordRoute*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionTimestamp *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionTimestamp*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionStreamId *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionStreamId*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionRouterAlert *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionRouterAlert*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionUnknown *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionUnknown*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionV2Marking *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionV2Marking*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4OptionSwift *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4OptionSwift*>(ptr.get<cObject>()); }
template<> inline inet::Ipv4Header *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv4Header*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_IPV4HEADER_M_H

