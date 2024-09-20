//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg.
//

#ifndef __INET_IEEE8021DBPDU_M_H
#define __INET_IEEE8021DBPDU_M_H

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

class BpduBase;
class BpduTcn;
class BpduCfg;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Enum generated from <tt>inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg:22</tt> by opp_msgtool.
 * <pre>
 * enum BpduProtocolIdentifier
 * {
 *     SPANNING_TREE_PROTOCOL = 0;
 * }
 * </pre>
 */
enum BpduProtocolIdentifier {
    SPANNING_TREE_PROTOCOL = 0
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BpduProtocolIdentifier& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BpduProtocolIdentifier& e) { int n; b->unpack(n); e = static_cast<BpduProtocolIdentifier>(n); }

/**
 * Enum generated from <tt>inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg:26</tt> by opp_msgtool.
 * <pre>
 * enum BpduProtocolVersionIdentifier
 * {
 *     SPANNING_TREE = 0;
 *     RAPID_SPANNING_TREE = 2;
 *     MULTIPLE_SPANNING_TREE = 3;
 * }
 * </pre>
 */
enum BpduProtocolVersionIdentifier {
    SPANNING_TREE = 0,
    RAPID_SPANNING_TREE = 2,
    MULTIPLE_SPANNING_TREE = 3
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BpduProtocolVersionIdentifier& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BpduProtocolVersionIdentifier& e) { int n; b->unpack(n); e = static_cast<BpduProtocolVersionIdentifier>(n); }

/**
 * Enum generated from <tt>inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg:32</tt> by opp_msgtool.
 * <pre>
 * enum BpduType
 * {
 *     BPDU_CFG = 0;
 *     BPDU_TCN = 0x80;
 *     BPDU_RAPID_OR_MULTIPLE_SPANNING_TREE = 0x02;
 * }
 * </pre>
 */
enum BpduType {
    BPDU_CFG = 0,
    BPDU_TCN = 0x80,
    BPDU_RAPID_OR_MULTIPLE_SPANNING_TREE = 0x02
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BpduType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BpduType& e) { int n; b->unpack(n); e = static_cast<BpduType>(n); }

/**
 * Class generated from <tt>inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg:43</tt> by opp_msgtool.
 * <pre>
 * //
 * // Represents a BPDU (Bridge PDU) used by the STP and RSTP protocols,
 * // as defined in the 802.1D-1998 specification.
 * //
 * class BpduBase extends FieldsChunk
 * {
 *     BpduProtocolIdentifier protocolIdentifier = static_cast<BpduProtocolIdentifier>(-1);    // 2 bytes, 0 for STP, 1 for RSTP (TODO use them)
 *     BpduProtocolVersionIdentifier protocolVersionIdentifier = static_cast<BpduProtocolVersionIdentifier>(-1);    // 1 byte, version ID, currently 0, // 3:MultipleSpanningTree
 *     BpduType bpduType = static_cast<BpduType>(-1);    // 1 byte, 0 for Configuration BPDU, 1 for Topology Change Notification BPDU
 * }
 * </pre>
 */
class INET_API BpduBase : public ::inet::FieldsChunk
{
  protected:
    BpduProtocolIdentifier protocolIdentifier = static_cast<BpduProtocolIdentifier>(-1);
    BpduProtocolVersionIdentifier protocolVersionIdentifier = static_cast<BpduProtocolVersionIdentifier>(-1);
    BpduType bpduType = static_cast<BpduType>(-1);

  private:
    void copy(const BpduBase& other);

  protected:
    bool operator==(const BpduBase&) = delete;

  public:
    BpduBase();
    BpduBase(const BpduBase& other);
    virtual ~BpduBase();
    BpduBase& operator=(const BpduBase& other);
    virtual BpduBase *dup() const override {return new BpduBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual BpduProtocolIdentifier getProtocolIdentifier() const;
    virtual void setProtocolIdentifier(BpduProtocolIdentifier protocolIdentifier);

    virtual BpduProtocolVersionIdentifier getProtocolVersionIdentifier() const;
    virtual void setProtocolVersionIdentifier(BpduProtocolVersionIdentifier protocolVersionIdentifier);

    virtual BpduType getBpduType() const;
    virtual void setBpduType(BpduType bpduType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BpduBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BpduBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg:50</tt> by opp_msgtool.
 * <pre>
 * class BpduTcn extends BpduBase
 * {
 *     chunkLength = B(4);
 *     protocolIdentifier = SPANNING_TREE_PROTOCOL;
 *     protocolVersionIdentifier = SPANNING_TREE;
 *     bpduType = BPDU_TCN;                            // Topology Change Notification BPDU
 * }
 * </pre>
 */
class INET_API BpduTcn : public ::inet::BpduBase
{
  protected:

  private:
    void copy(const BpduTcn& other);

  protected:
    bool operator==(const BpduTcn&) = delete;

  public:
    BpduTcn();
    BpduTcn(const BpduTcn& other);
    virtual ~BpduTcn();
    BpduTcn& operator=(const BpduTcn& other);
    virtual BpduTcn *dup() const override {return new BpduTcn(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BpduTcn& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BpduTcn& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg:58</tt> by opp_msgtool.
 * <pre>
 * class BpduCfg extends BpduBase
 * {
 *     chunkLength = B(35);
 *     protocolIdentifier = SPANNING_TREE_PROTOCOL;
 *     protocolVersionIdentifier = SPANNING_TREE;
 *     bpduType = BPDU_CFG;
 *                                               // flags: 1 byte
 *     bool tcaFlag;                             //   Topology Change Acknowledgment flag
 *     uint8_t reserved = 0;                     //   unused 6 bits of Flags
 *     bool tcFlag;                              //   Topology Change flag
 * 
 *     uint16_t rootPriority;                    // 2 bytes, priority of the tree root (part of Root Identifier)
 *     MacAddress rootAddress;                   // 6 bytes, address of the tree root (part of Root Identifier)
 *     uint32_t rootPathCost;                    // 4 bytes, cost to the root
 * 
 *     uint16_t bridgePriority;                  // 2 bytes, priority of sender bridge (part of Bridge Identifier)
 *     MacAddress bridgeAddress;                 // 6 bytes, address of sender bridge (part of Bridge Identifier)
 * 
 *     unsigned int portPriority;                // 1 byte, priority of sender port (part of Port Identifier)
 *     unsigned int portNum;                     // 1 byte, port number (ethg[] gate index) of sender port (part of Port Identifier)
 *                                               // (or 4 bit priority (shifted with 4 bit) and 12 bit portnum (in 802.1D-2004))
 * 
 *     simtime_t messageAge;                     // 2 bytes, Message Age (in 256ths of a second)
 *     simtime_t maxAge;                         // 2 bytes, maximum lifetime of the BPDU (in 256ths of a second)
 *     simtime_t helloTime;                      // 2 bytes, Hello Time of the sender bridge (in 256ths of a second)
 *     simtime_t forwardDelay;                   // 2 bytes, Forward Delay timer of the sender bridge (in 256ths of a second)
 * }
 * </pre>
 */
class INET_API BpduCfg : public ::inet::BpduBase
{
  protected:
    bool tcaFlag = false;
    uint8_t reserved = 0;
    bool tcFlag = false;
    uint16_t rootPriority = 0;
    MacAddress rootAddress;
    uint32_t rootPathCost = 0;
    uint16_t bridgePriority = 0;
    MacAddress bridgeAddress;
    unsigned int portPriority = 0;
    unsigned int portNum = 0;
    ::omnetpp::simtime_t messageAge = SIMTIME_ZERO;
    ::omnetpp::simtime_t maxAge = SIMTIME_ZERO;
    ::omnetpp::simtime_t helloTime = SIMTIME_ZERO;
    ::omnetpp::simtime_t forwardDelay = SIMTIME_ZERO;

  private:
    void copy(const BpduCfg& other);

  protected:
    bool operator==(const BpduCfg&) = delete;

  public:
    BpduCfg();
    BpduCfg(const BpduCfg& other);
    virtual ~BpduCfg();
    BpduCfg& operator=(const BpduCfg& other);
    virtual BpduCfg *dup() const override {return new BpduCfg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual bool getTcaFlag() const;
    virtual void setTcaFlag(bool tcaFlag);

    virtual uint8_t getReserved() const;
    virtual void setReserved(uint8_t reserved);

    virtual bool getTcFlag() const;
    virtual void setTcFlag(bool tcFlag);

    virtual uint16_t getRootPriority() const;
    virtual void setRootPriority(uint16_t rootPriority);

    virtual const MacAddress& getRootAddress() const;
    virtual MacAddress& getRootAddressForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<BpduCfg*>(this)->getRootAddress());}
    virtual void setRootAddress(const MacAddress& rootAddress);

    virtual uint32_t getRootPathCost() const;
    virtual void setRootPathCost(uint32_t rootPathCost);

    virtual uint16_t getBridgePriority() const;
    virtual void setBridgePriority(uint16_t bridgePriority);

    virtual const MacAddress& getBridgeAddress() const;
    virtual MacAddress& getBridgeAddressForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<BpduCfg*>(this)->getBridgeAddress());}
    virtual void setBridgeAddress(const MacAddress& bridgeAddress);

    virtual unsigned int getPortPriority() const;
    virtual void setPortPriority(unsigned int portPriority);

    virtual unsigned int getPortNum() const;
    virtual void setPortNum(unsigned int portNum);

    virtual ::omnetpp::simtime_t getMessageAge() const;
    virtual void setMessageAge(::omnetpp::simtime_t messageAge);

    virtual ::omnetpp::simtime_t getMaxAge() const;
    virtual void setMaxAge(::omnetpp::simtime_t maxAge);

    virtual ::omnetpp::simtime_t getHelloTime() const;
    virtual void setHelloTime(::omnetpp::simtime_t helloTime);

    virtual ::omnetpp::simtime_t getForwardDelay() const;
    virtual void setForwardDelay(::omnetpp::simtime_t forwardDelay);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BpduCfg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BpduCfg& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::BpduBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::BpduBase*>(ptr.get<cObject>()); }
template<> inline inet::BpduTcn *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::BpduTcn*>(ptr.get<cObject>()); }
template<> inline inet::BpduCfg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::BpduCfg*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_IEEE8021DBPDU_M_H

