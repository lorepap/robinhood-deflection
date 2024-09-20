//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/common/InterfaceTag.msg.
//

#ifndef __INET_INTERFACETAG_M_H
#define __INET_INTERFACETAG_M_H

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

class InterfaceTagBase;
class PacketInsertionControlTag;
class InterfaceReq;
class InterfaceInd;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/common/InterfaceTag.msg:11</tt> by opp_msgtool.
 * <pre>
 * class InterfaceTagBase extends TagBase
 * {
 *     int interfaceId = -1; // a locally unique (network node) identifier that determines the interface registered in the ~InterfaceTable  
 * }
 * </pre>
 */
class INET_API InterfaceTagBase : public ::inet::TagBase
{
  protected:
    int interfaceId = -1;

  private:
    void copy(const InterfaceTagBase& other);

  protected:
    bool operator==(const InterfaceTagBase&) = delete;

  public:
    InterfaceTagBase();
    InterfaceTagBase(const InterfaceTagBase& other);
    virtual ~InterfaceTagBase();
    InterfaceTagBase& operator=(const InterfaceTagBase& other);
    virtual InterfaceTagBase *dup() const override {return new InterfaceTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getInterfaceId() const;
    virtual void setInterfaceId(int interfaceId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const InterfaceTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, InterfaceTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/InterfaceTag.msg:16</tt> by opp_msgtool.
 * <pre>
 * class PacketInsertionControlTag extends TagBase
 * {
 *     bool insert_packet_without_checking_the_queue; // if true, packet is cleared to be inserted right away
 * }
 * </pre>
 */
class INET_API PacketInsertionControlTag : public ::inet::TagBase
{
  protected:
    bool insert_packet_without_checking_the_queue = false;

  private:
    void copy(const PacketInsertionControlTag& other);

  protected:
    bool operator==(const PacketInsertionControlTag&) = delete;

  public:
    PacketInsertionControlTag();
    PacketInsertionControlTag(const PacketInsertionControlTag& other);
    virtual ~PacketInsertionControlTag();
    PacketInsertionControlTag& operator=(const PacketInsertionControlTag& other);
    virtual PacketInsertionControlTag *dup() const override {return new PacketInsertionControlTag(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual bool getInsert_packet_without_checking_the_queue() const;
    virtual void setInsert_packet_without_checking_the_queue(bool insert_packet_without_checking_the_queue);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PacketInsertionControlTag& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PacketInsertionControlTag& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/InterfaceTag.msg:24</tt> by opp_msgtool.
 * <pre>
 * //
 * // Determines the outgoing interface where the packet should leave the network node.
 * //
 * class InterfaceReq extends InterfaceTagBase
 * {
 * }
 * </pre>
 */
class INET_API InterfaceReq : public ::inet::InterfaceTagBase
{
  protected:

  private:
    void copy(const InterfaceReq& other);

  protected:
    bool operator==(const InterfaceReq&) = delete;

  public:
    InterfaceReq();
    InterfaceReq(const InterfaceReq& other);
    virtual ~InterfaceReq();
    InterfaceReq& operator=(const InterfaceReq& other);
    virtual InterfaceReq *dup() const override {return new InterfaceReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const InterfaceReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, InterfaceReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/InterfaceTag.msg:31</tt> by opp_msgtool.
 * <pre>
 * //
 * // Specifies the incoming interface where the packet has arrived at the network node.
 * //
 * class InterfaceInd extends InterfaceTagBase
 * {
 * }
 * </pre>
 */
class INET_API InterfaceInd : public ::inet::InterfaceTagBase
{
  protected:

  private:
    void copy(const InterfaceInd& other);

  protected:
    bool operator==(const InterfaceInd&) = delete;

  public:
    InterfaceInd();
    InterfaceInd(const InterfaceInd& other);
    virtual ~InterfaceInd();
    InterfaceInd& operator=(const InterfaceInd& other);
    virtual InterfaceInd *dup() const override {return new InterfaceInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const InterfaceInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, InterfaceInd& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::InterfaceTagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::InterfaceTagBase*>(ptr.get<cObject>()); }
template<> inline inet::PacketInsertionControlTag *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::PacketInsertionControlTag*>(ptr.get<cObject>()); }
template<> inline inet::InterfaceReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::InterfaceReq*>(ptr.get<cObject>()); }
template<> inline inet::InterfaceInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::InterfaceInd*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_INTERFACETAG_M_H

