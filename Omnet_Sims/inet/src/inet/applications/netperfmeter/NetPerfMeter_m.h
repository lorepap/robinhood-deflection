//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/applications/netperfmeter/NetPerfMeter.msg.
//

#ifndef __INET_NETPERFMETER_M_H
#define __INET_NETPERFMETER_M_H

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

class NetPerfMeterTransmitTimer;
class NetPerfMeterDataMessage;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/transportlayer/contract/sctp/SctpCommand_m.h" // import inet.transportlayer.contract.sctp.SctpCommand


namespace inet {

/**
 * Class generated from <tt>inet/applications/netperfmeter/NetPerfMeter.msg:35</tt> by opp_msgtool.
 * <pre>
 * message NetPerfMeterTransmitTimer
 * {
 *     unsigned int streamID;
 * }
 * </pre>
 */
class INET_API NetPerfMeterTransmitTimer : public ::omnetpp::cMessage
{
  protected:
    unsigned int streamID = 0;

  private:
    void copy(const NetPerfMeterTransmitTimer& other);

  protected:
    bool operator==(const NetPerfMeterTransmitTimer&) = delete;

  public:
    NetPerfMeterTransmitTimer(const char *name=nullptr, short kind=0);
    NetPerfMeterTransmitTimer(const NetPerfMeterTransmitTimer& other);
    virtual ~NetPerfMeterTransmitTimer();
    NetPerfMeterTransmitTimer& operator=(const NetPerfMeterTransmitTimer& other);
    virtual NetPerfMeterTransmitTimer *dup() const override {return new NetPerfMeterTransmitTimer(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual unsigned int getStreamID() const;
    virtual void setStreamID(unsigned int streamID);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NetPerfMeterTransmitTimer& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NetPerfMeterTransmitTimer& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/applications/netperfmeter/NetPerfMeter.msg:41</tt> by opp_msgtool.
 * <pre>
 * class NetPerfMeterDataMessage extends SctpSimpleMessage
 * {
 * }
 * </pre>
 */
class INET_API NetPerfMeterDataMessage : public ::inet::SctpSimpleMessage
{
  protected:

  private:
    void copy(const NetPerfMeterDataMessage& other);

  protected:
    bool operator==(const NetPerfMeterDataMessage&) = delete;

  public:
    NetPerfMeterDataMessage(const char *name=nullptr);
    NetPerfMeterDataMessage(const NetPerfMeterDataMessage& other);
    virtual ~NetPerfMeterDataMessage();
    NetPerfMeterDataMessage& operator=(const NetPerfMeterDataMessage& other);
    virtual NetPerfMeterDataMessage *dup() const override {return new NetPerfMeterDataMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NetPerfMeterDataMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NetPerfMeterDataMessage& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::NetPerfMeterTransmitTimer *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::NetPerfMeterTransmitTimer*>(ptr.get<cObject>()); }
template<> inline inet::NetPerfMeterDataMessage *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::NetPerfMeterDataMessage*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_NETPERFMETER_M_H

