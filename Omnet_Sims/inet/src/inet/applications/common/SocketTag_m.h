//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/applications/common/SocketTag.msg.
//

#ifndef __INET_SOCKETTAG_M_H
#define __INET_SOCKETTAG_M_H

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

class SocketTagBase;
class SocketReq;
class SocketInd;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/applications/common/SocketTag.msg:11</tt> by opp_msgtool.
 * <pre>
 * class SocketTagBase extends TagBase
 * {
 *     int socketId = -1; // a locally unique (network node) identifier that determines the application socket
 * }
 * </pre>
 */
class INET_API SocketTagBase : public ::inet::TagBase
{
  protected:
    int socketId = -1;

  private:
    void copy(const SocketTagBase& other);

  protected:
    bool operator==(const SocketTagBase&) = delete;

  public:
    SocketTagBase();
    SocketTagBase(const SocketTagBase& other);
    virtual ~SocketTagBase();
    SocketTagBase& operator=(const SocketTagBase& other);
    virtual SocketTagBase *dup() const override {return new SocketTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getSocketId() const;
    virtual void setSocketId(int socketId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SocketTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SocketTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/applications/common/SocketTag.msg:19</tt> by opp_msgtool.
 * <pre>
 * //
 * // Determines the application socket of an outgoing packet, sent by the application.
 * //
 * class SocketReq extends SocketTagBase
 * {
 * }
 * </pre>
 */
class INET_API SocketReq : public ::inet::SocketTagBase
{
  protected:

  private:
    void copy(const SocketReq& other);

  protected:
    bool operator==(const SocketReq&) = delete;

  public:
    SocketReq();
    SocketReq(const SocketReq& other);
    virtual ~SocketReq();
    SocketReq& operator=(const SocketReq& other);
    virtual SocketReq *dup() const override {return new SocketReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SocketReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SocketReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/applications/common/SocketTag.msg:26</tt> by opp_msgtool.
 * <pre>
 * //
 * // Specifies the application socket of an incoming packet, received by the application.
 * //
 * class SocketInd extends SocketTagBase
 * {
 * }
 * </pre>
 */
class INET_API SocketInd : public ::inet::SocketTagBase
{
  protected:

  private:
    void copy(const SocketInd& other);

  protected:
    bool operator==(const SocketInd&) = delete;

  public:
    SocketInd();
    SocketInd(const SocketInd& other);
    virtual ~SocketInd();
    SocketInd& operator=(const SocketInd& other);
    virtual SocketInd *dup() const override {return new SocketInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SocketInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SocketInd& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::SocketTagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::SocketTagBase*>(ptr.get<cObject>()); }
template<> inline inet::SocketReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::SocketReq*>(ptr.get<cObject>()); }
template<> inline inet::SocketInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::SocketInd*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_SOCKETTAG_M_H

