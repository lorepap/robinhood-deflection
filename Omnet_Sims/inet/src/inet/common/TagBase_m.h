//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/common/TagBase.msg.
//

#ifndef __INET_TAGBASE_M_H
#define __INET_TAGBASE_M_H

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

class TagBase;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs


namespace inet {

/**
 * Class generated from <tt>inet/common/TagBase.msg:14</tt> by opp_msgtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added to a message as a tag.
 * // It is used as the base class of all tags, thus it doesn't have any fields.
 * //
 * class TagBase extends cObject
 * {
 * }
 * </pre>
 */
class INET_API TagBase : public ::omnetpp::cObject
{
  protected:

  private:
    void copy(const TagBase& other);

  protected:
    bool operator==(const TagBase&) = delete;

  public:
    TagBase();
    TagBase(const TagBase& other);
    virtual ~TagBase();
    TagBase& operator=(const TagBase& other);
    virtual TagBase *dup() const override {return new TagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TagBase& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::TagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::TagBase*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_TAGBASE_M_H

