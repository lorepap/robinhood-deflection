//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/rsvpte/RsvpPathMsg.msg.
//

#ifndef __INET_RSVPPATHMSG_M_H
#define __INET_RSVPPATHMSG_M_H

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

class RsvpPathMsg;
class RsvpPathTear;
class RsvpPathError;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

#include "inet/networklayer/rsvpte/IntServ_m.h" // import inet.networklayer.rsvpte.IntServ

#include "inet/networklayer/rsvpte/RsvpPacket_m.h" // import inet.networklayer.rsvpte.RsvpPacket


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/rsvpte/RsvpPathMsg.msg:27</tt> by opp_msgtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * class RsvpPathMsg extends RsvpPacket
 * {
 *     RsvpHopObj hop;
 *     LabelRequestObj label_request;
 *     SenderDescriptor_t sender_descriptor;
 *     EroVector ERO;
 *     int color;
 * 
 *     rsvpKind = PATH_MESSAGE;
 * }
 * </pre>
 */
class INET_API RsvpPathMsg : public ::inet::RsvpPacket
{
  protected:
    RsvpHopObj hop;
    LabelRequestObj label_request;
    SenderDescriptor_t sender_descriptor;
    EroVector ERO;
    int color = 0;

  private:
    void copy(const RsvpPathMsg& other);

  protected:
    bool operator==(const RsvpPathMsg&) = delete;

  public:
    RsvpPathMsg();
    RsvpPathMsg(const RsvpPathMsg& other);
    virtual ~RsvpPathMsg();
    RsvpPathMsg& operator=(const RsvpPathMsg& other);
    virtual RsvpPathMsg *dup() const override {return new RsvpPathMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const RsvpHopObj& getHop() const;
    virtual RsvpHopObj& getHopForUpdate() { handleChange();return const_cast<RsvpHopObj&>(const_cast<RsvpPathMsg*>(this)->getHop());}
    virtual void setHop(const RsvpHopObj& hop);

    virtual const LabelRequestObj& getLabel_request() const;
    virtual LabelRequestObj& getLabel_requestForUpdate() { handleChange();return const_cast<LabelRequestObj&>(const_cast<RsvpPathMsg*>(this)->getLabel_request());}
    virtual void setLabel_request(const LabelRequestObj& label_request);

    virtual const SenderDescriptor_t& getSender_descriptor() const;
    virtual SenderDescriptor_t& getSender_descriptorForUpdate() { handleChange();return const_cast<SenderDescriptor_t&>(const_cast<RsvpPathMsg*>(this)->getSender_descriptor());}
    virtual void setSender_descriptor(const SenderDescriptor_t& sender_descriptor);

    virtual const EroVector& getERO() const;
    virtual EroVector& getEROForUpdate() { handleChange();return const_cast<EroVector&>(const_cast<RsvpPathMsg*>(this)->getERO());}
    virtual void setERO(const EroVector& ERO);

    virtual int getColor() const;
    virtual void setColor(int color);


  public:
    inline Ipv4Address getSrcAddress() { return getSender_descriptor().Sender_Template_Object.SrcAddress; }
    inline int getLspId() const { return getSender_descriptor().Sender_Template_Object.Lsp_Id; }
    inline Ipv4Address getNHOP() { return getHop().Next_Hop_Address; }
    inline Ipv4Address getLIH() { return getHop().Logical_Interface_Handle; }
    inline double getBW() { return getSender_descriptor().Sender_Tspec_Object.req_bandwidth; }
    inline SenderTemplateObj& getSenderTemplateForUpdate() { return getSender_descriptorForUpdate().Sender_Template_Object; }
    inline const SenderTemplateObj& getSenderTemplate() const { return getSender_descriptor().Sender_Template_Object; }
    inline void setSenderTemplate(const SenderTemplateObj& s) { getSender_descriptorForUpdate().Sender_Template_Object = s; }
    inline SenderTspecObj& getSenderTspecForUpdate() { return getSender_descriptorForUpdate().Sender_Tspec_Object; }
    inline const SenderTspecObj& getSenderTspec() { return getSender_descriptor().Sender_Tspec_Object; }
    inline void setSenderTspec(const SenderTspecObj& s) { getSender_descriptorForUpdate().Sender_Tspec_Object = s; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RsvpPathMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RsvpPathMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/RsvpPathMsg.msg:56</tt> by opp_msgtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * class RsvpPathTear extends RsvpPacket
 * {
 *     RsvpHopObj hop;
 *     SenderTemplateObj senderTemplate;
 *     bool force;
 *     rsvpKind = PTEAR_MESSAGE;
 * }
 * </pre>
 */
class INET_API RsvpPathTear : public ::inet::RsvpPacket
{
  protected:
    RsvpHopObj hop;
    SenderTemplateObj senderTemplate;
    bool force = false;

  private:
    void copy(const RsvpPathTear& other);

  protected:
    bool operator==(const RsvpPathTear&) = delete;

  public:
    RsvpPathTear();
    RsvpPathTear(const RsvpPathTear& other);
    virtual ~RsvpPathTear();
    RsvpPathTear& operator=(const RsvpPathTear& other);
    virtual RsvpPathTear *dup() const override {return new RsvpPathTear(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const RsvpHopObj& getHop() const;
    virtual RsvpHopObj& getHopForUpdate() { handleChange();return const_cast<RsvpHopObj&>(const_cast<RsvpPathTear*>(this)->getHop());}
    virtual void setHop(const RsvpHopObj& hop);

    virtual const SenderTemplateObj& getSenderTemplate() const;
    virtual SenderTemplateObj& getSenderTemplateForUpdate() { handleChange();return const_cast<SenderTemplateObj&>(const_cast<RsvpPathTear*>(this)->getSenderTemplate());}
    virtual void setSenderTemplate(const SenderTemplateObj& senderTemplate);

    virtual bool getForce() const;
    virtual void setForce(bool force);


  public:
    inline Ipv4Address getNHOP() { return getHop().Next_Hop_Address; }
    inline Ipv4Address getLIH() { return getHop().Logical_Interface_Handle; }
    inline Ipv4Address getSrcAddress() { return getSenderTemplate().SrcAddress; }
    inline int getLspId() const { return getSenderTemplate().Lsp_Id; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RsvpPathTear& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RsvpPathTear& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/RsvpPathMsg.msg:74</tt> by opp_msgtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * class RsvpPathError extends RsvpPacket
 * {
 *     Ipv4Address errorNode;
 *     int errorCode;
 *     SenderDescriptor_t sender_descriptor;
 * 
 *     rsvpKind = PERROR_MESSAGE;
 * }
 * </pre>
 */
class INET_API RsvpPathError : public ::inet::RsvpPacket
{
  protected:
    Ipv4Address errorNode;
    int errorCode = 0;
    SenderDescriptor_t sender_descriptor;

  private:
    void copy(const RsvpPathError& other);

  protected:
    bool operator==(const RsvpPathError&) = delete;

  public:
    RsvpPathError();
    RsvpPathError(const RsvpPathError& other);
    virtual ~RsvpPathError();
    RsvpPathError& operator=(const RsvpPathError& other);
    virtual RsvpPathError *dup() const override {return new RsvpPathError(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Ipv4Address& getErrorNode() const;
    virtual Ipv4Address& getErrorNodeForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<RsvpPathError*>(this)->getErrorNode());}
    virtual void setErrorNode(const Ipv4Address& errorNode);

    virtual int getErrorCode() const;
    virtual void setErrorCode(int errorCode);

    virtual const SenderDescriptor_t& getSender_descriptor() const;
    virtual SenderDescriptor_t& getSender_descriptorForUpdate() { handleChange();return const_cast<SenderDescriptor_t&>(const_cast<RsvpPathError*>(this)->getSender_descriptor());}
    virtual void setSender_descriptor(const SenderDescriptor_t& sender_descriptor);


  public:
    inline Ipv4Address getSrcAddress() { return getSender_descriptor().Sender_Template_Object.SrcAddress; }
    inline int getLspId() { return getSender_descriptor().Sender_Template_Object.Lsp_Id; }
    inline double getBW() { return getSender_descriptor().Sender_Tspec_Object.req_bandwidth; }

    inline SenderTemplateObj& getSenderTemplateForUpdate() { return getSender_descriptorForUpdate().Sender_Template_Object; }
    inline const SenderTemplateObj& getSenderTemplate() const { return getSender_descriptor().Sender_Template_Object; }
    inline void setSenderTemplate(const SenderTemplateObj& s) { getSender_descriptorForUpdate().Sender_Template_Object = s; }
    inline SenderTspecObj& getSenderTspecForUpdate() { return getSender_descriptorForUpdate().Sender_Tspec_Object; }
    inline const SenderTspecObj& getSenderTspec() const { return getSender_descriptor().Sender_Tspec_Object; }
    inline void setSenderTspec(const SenderTspecObj& s) { getSender_descriptorForUpdate().Sender_Tspec_Object = s; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RsvpPathError& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RsvpPathError& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::RsvpPathMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::RsvpPathMsg*>(ptr.get<cObject>()); }
template<> inline inet::RsvpPathTear *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::RsvpPathTear*>(ptr.get<cObject>()); }
template<> inline inet::RsvpPathError *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::RsvpPathError*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_RSVPPATHMSG_M_H

