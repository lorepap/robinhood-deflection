//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/applications/httptools/common/HttpMessages.msg.
//

#ifndef __INET__HTTPTOOLS_HTTPMESSAGES_M_H
#define __INET__HTTPTOOLS_HTTPMESSAGES_M_H

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
namespace httptools {

class HttpBaseMessage;
class HttpRequestMessage;
class HttpReplyMessage;

}  // namespace httptools
}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/transportlayer/common/CrcMode_m.h" // import inet.transportlayer.common.CrcMode


namespace inet {
namespace httptools {

/**
 * Class generated from <tt>inet/applications/httptools/common/HttpMessages.msg:76</tt> by opp_msgtool.
 * <pre>
 * //
 * // Base class for HTTP messages
 * //
 * class HttpBaseMessage extends FieldsChunk
 * {
 *     string targetUrl;               // The target URL - request set for browsers, echoed by servers.
 *     string originatorUrl = "";      // The originator URL. Only applicable for servers.
 *     int protocol = 11;              // 10 for http/1.0, 11 for http/1.1.
 *     bool keepAlive = true;          // The keep-alive header
 *     int serial = 0;                 // Convenience field which allows resource requests to be serially tagged for ease of analysis.
 *     string heading = "";                // The message heading - request string for requests, response for replies
 *     string payload = "";                // The payload field
 * }
 * </pre>
 */
class INET_API HttpBaseMessage : public ::inet::FieldsChunk
{
  protected:
    ::omnetpp::opp_string targetUrl;
    ::omnetpp::opp_string originatorUrl = "";
    int protocol = 11;
    bool keepAlive = true;
    int serial = 0;
    ::omnetpp::opp_string heading = "";
    ::omnetpp::opp_string payload = "";

  private:
    void copy(const HttpBaseMessage& other);

  protected:
    bool operator==(const HttpBaseMessage&) = delete;

  public:
    HttpBaseMessage();
    HttpBaseMessage(const HttpBaseMessage& other);
    virtual ~HttpBaseMessage();
    HttpBaseMessage& operator=(const HttpBaseMessage& other);
    virtual HttpBaseMessage *dup() const override {return new HttpBaseMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const char * getTargetUrl() const;
    virtual void setTargetUrl(const char * targetUrl);

    virtual const char * getOriginatorUrl() const;
    virtual void setOriginatorUrl(const char * originatorUrl);

    virtual int getProtocol() const;
    virtual void setProtocol(int protocol);

    virtual bool getKeepAlive() const;
    virtual void setKeepAlive(bool keepAlive);

    virtual int getSerial() const;
    virtual void setSerial(int serial);

    virtual const char * getHeading() const;
    virtual void setHeading(const char * heading);

    virtual const char * getPayload() const;
    virtual void setPayload(const char * payload);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HttpBaseMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HttpBaseMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/applications/httptools/common/HttpMessages.msg:90</tt> by opp_msgtool.
 * <pre>
 * //
 * // Message class for HTTP requests
 * //
 * class HttpRequestMessage extends HttpBaseMessage
 * {
 *     bool badRequest = false;    // Set to true to simulate a bad request. Server answers w. 404.
 * }
 * </pre>
 */
class INET_API HttpRequestMessage : public ::inet::httptools::HttpBaseMessage
{
  protected:
    bool badRequest = false;

  private:
    void copy(const HttpRequestMessage& other);

  protected:
    bool operator==(const HttpRequestMessage&) = delete;

  public:
    HttpRequestMessage();
    HttpRequestMessage(const HttpRequestMessage& other);
    virtual ~HttpRequestMessage();
    HttpRequestMessage& operator=(const HttpRequestMessage& other);
    virtual HttpRequestMessage *dup() const override {return new HttpRequestMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual bool getBadRequest() const;
    virtual void setBadRequest(bool badRequest);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HttpRequestMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HttpRequestMessage& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>inet/applications/httptools/common/HttpMessages.msg:99</tt> by opp_msgtool.
 * <pre>
 * //
 * // Content type of HTTP responses.
 * //
 * enum HttpContentType
 * {
 *     CT_UNKNOWN = 0;
 *     CT_HTML = 1;
 *     CT_IMAGE = 2;
 *     CT_TEXT = 3;
 * }
 * </pre>
 */
enum HttpContentType {
    CT_UNKNOWN = 0,
    CT_HTML = 1,
    CT_IMAGE = 2,
    CT_TEXT = 3
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HttpContentType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HttpContentType& e) { int n; b->unpack(n); e = static_cast<HttpContentType>(n); }

/**
 * Class generated from <tt>inet/applications/httptools/common/HttpMessages.msg:111</tt> by opp_msgtool.
 * <pre>
 * //
 * // Message class for HTTP replies
 * //
 * class HttpReplyMessage extends HttpBaseMessage
 * {
 *     int result = 0;      // e.g. 200 for OK, 404 for NOT FOUND.
 *     HttpContentType contentType = CT_UNKNOWN;
 * }
 * </pre>
 */
class INET_API HttpReplyMessage : public ::inet::httptools::HttpBaseMessage
{
  protected:
    int result = 0;
    HttpContentType contentType = CT_UNKNOWN;

  private:
    void copy(const HttpReplyMessage& other);

  protected:
    bool operator==(const HttpReplyMessage&) = delete;

  public:
    HttpReplyMessage();
    HttpReplyMessage(const HttpReplyMessage& other);
    virtual ~HttpReplyMessage();
    HttpReplyMessage& operator=(const HttpReplyMessage& other);
    virtual HttpReplyMessage *dup() const override {return new HttpReplyMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getResult() const;
    virtual void setResult(int result);

    virtual HttpContentType getContentType() const;
    virtual void setContentType(HttpContentType contentType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HttpReplyMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HttpReplyMessage& obj) {obj.parsimUnpack(b);}


}  // namespace httptools
}  // namespace inet


namespace omnetpp {

template<> inline inet::httptools::HttpBaseMessage *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::httptools::HttpBaseMessage*>(ptr.get<cObject>()); }
template<> inline inet::httptools::HttpRequestMessage *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::httptools::HttpRequestMessage*>(ptr.get<cObject>()); }
template<> inline inet::httptools::HttpReplyMessage *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::httptools::HttpReplyMessage*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET__HTTPTOOLS_HTTPMESSAGES_M_H

