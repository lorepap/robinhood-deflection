//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/ethernet/EtherFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "EtherFrame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

Register_Enum(inet::EthernetControlOpCode, (inet::EthernetControlOpCode::ETHERNET_CONTROL_PAUSE));

Register_Class(EthernetMacHeader)

EthernetMacHeader::EthernetMacHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(ETHER_MAC_HEADER_BYTES));

}

EthernetMacHeader::EthernetMacHeader(const EthernetMacHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EthernetMacHeader::~EthernetMacHeader()
{
    delete this->cTag;
    delete this->sTag;
}

EthernetMacHeader& EthernetMacHeader::operator=(const EthernetMacHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EthernetMacHeader::copy(const EthernetMacHeader& other)
{
    this->dest = other.dest;
    this->src = other.src;
    delete this->cTag;
    this->cTag = other.cTag;
    if (this->cTag != nullptr) {
        this->cTag = this->cTag->dup();
    }
    delete this->sTag;
    this->sTag = other.sTag;
    if (this->sTag != nullptr) {
        this->sTag = this->sTag->dup();
    }
    this->typeOrLength = other.typeOrLength;
    this->hop_count = other.hop_count;
    this->isFB_ = other.isFB_;
    this->allow_same_input_output = other.allow_same_input_output;
    this->original_interface_id = other.original_interface_id;
    this->bouncedDistance = other.bouncedDistance;
    this->maxBouncedDistance = other.maxBouncedDistance;
    this->bouncedHop = other.bouncedHop;
    this->totalHopNum = other.totalHopNum;
    this->is_bursty = other.is_bursty;
    this->payload_length = other.payload_length;
    this->total_length = other.total_length;
    this->offset = other.offset;
    this->is_v2_dropped_packet_header = other.is_v2_dropped_packet_header;
    this->queue_occupancy = other.queue_occupancy;
    this->time_packet_received_at_nic = other.time_packet_received_at_nic;
    this->local_nic_rx_delay = other.local_nic_rx_delay;
    this->remote_queueing_time = other.remote_queueing_time;
    this->fabric_delay_time_sent_from_source = other.fabric_delay_time_sent_from_source;
    this->time_packet_sent_from_src = other.time_packet_sent_from_src;
    this->is_deflected = other.is_deflected;
}

void EthernetMacHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->dest);
    doParsimPacking(b,this->src);
    doParsimPacking(b,this->cTag);
    doParsimPacking(b,this->sTag);
    doParsimPacking(b,this->typeOrLength);
    doParsimPacking(b,this->hop_count);
    doParsimPacking(b,this->isFB_);
    doParsimPacking(b,this->allow_same_input_output);
    doParsimPacking(b,this->original_interface_id);
    doParsimPacking(b,this->bouncedDistance);
    doParsimPacking(b,this->maxBouncedDistance);
    doParsimPacking(b,this->bouncedHop);
    doParsimPacking(b,this->totalHopNum);
    doParsimPacking(b,this->is_bursty);
    doParsimPacking(b,this->payload_length);
    doParsimPacking(b,this->total_length);
    doParsimPacking(b,this->offset);
    doParsimPacking(b,this->is_v2_dropped_packet_header);
    doParsimPacking(b,this->queue_occupancy);
    doParsimPacking(b,this->time_packet_received_at_nic);
    doParsimPacking(b,this->local_nic_rx_delay);
    doParsimPacking(b,this->remote_queueing_time);
    doParsimPacking(b,this->fabric_delay_time_sent_from_source);
    doParsimPacking(b,this->time_packet_sent_from_src);
    doParsimPacking(b,this->is_deflected);
}

void EthernetMacHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->dest);
    doParsimUnpacking(b,this->src);
    doParsimUnpacking(b,this->cTag);
    doParsimUnpacking(b,this->sTag);
    doParsimUnpacking(b,this->typeOrLength);
    doParsimUnpacking(b,this->hop_count);
    doParsimUnpacking(b,this->isFB_);
    doParsimUnpacking(b,this->allow_same_input_output);
    doParsimUnpacking(b,this->original_interface_id);
    doParsimUnpacking(b,this->bouncedDistance);
    doParsimUnpacking(b,this->maxBouncedDistance);
    doParsimUnpacking(b,this->bouncedHop);
    doParsimUnpacking(b,this->totalHopNum);
    doParsimUnpacking(b,this->is_bursty);
    doParsimUnpacking(b,this->payload_length);
    doParsimUnpacking(b,this->total_length);
    doParsimUnpacking(b,this->offset);
    doParsimUnpacking(b,this->is_v2_dropped_packet_header);
    doParsimUnpacking(b,this->queue_occupancy);
    doParsimUnpacking(b,this->time_packet_received_at_nic);
    doParsimUnpacking(b,this->local_nic_rx_delay);
    doParsimUnpacking(b,this->remote_queueing_time);
    doParsimUnpacking(b,this->fabric_delay_time_sent_from_source);
    doParsimUnpacking(b,this->time_packet_sent_from_src);
    doParsimUnpacking(b,this->is_deflected);
}

const MacAddress& EthernetMacHeader::getDest() const
{
    return this->dest;
}

void EthernetMacHeader::setDest(const MacAddress& dest)
{
    handleChange();
    this->dest = dest;
}

const MacAddress& EthernetMacHeader::getSrc() const
{
    return this->src;
}

void EthernetMacHeader::setSrc(const MacAddress& src)
{
    handleChange();
    this->src = src;
}

const Ieee8021qHeader * EthernetMacHeader::getCTag() const
{
    return this->cTag;
}

void EthernetMacHeader::setCTag(Ieee8021qHeader * cTag)
{
    handleChange();
    if (this->cTag != nullptr) throw omnetpp::cRuntimeError("setCTag(): a value is already set, remove it first with removeCTag()");
    this->cTag = cTag;
    if (this->cTag != nullptr && this->cTag->isOwnedObject()) take((cOwnedObject*)this->cTag);
}

Ieee8021qHeader * EthernetMacHeader::removeCTag()
{
    handleChange();
    Ieee8021qHeader * retval = this->cTag;
    if (retval != nullptr && retval->isOwnedObject()) drop((cOwnedObject*)retval);
    this->cTag = nullptr;
    return retval;
}

const Ieee8021qHeader * EthernetMacHeader::getSTag() const
{
    return this->sTag;
}

void EthernetMacHeader::setSTag(Ieee8021qHeader * sTag)
{
    handleChange();
    if (this->sTag != nullptr) throw omnetpp::cRuntimeError("setSTag(): a value is already set, remove it first with removeSTag()");
    this->sTag = sTag;
    if (this->sTag != nullptr && this->sTag->isOwnedObject()) take((cOwnedObject*)this->sTag);
}

Ieee8021qHeader * EthernetMacHeader::removeSTag()
{
    handleChange();
    Ieee8021qHeader * retval = this->sTag;
    if (retval != nullptr && retval->isOwnedObject()) drop((cOwnedObject*)retval);
    this->sTag = nullptr;
    return retval;
}

int EthernetMacHeader::getTypeOrLength() const
{
    return this->typeOrLength;
}

void EthernetMacHeader::setTypeOrLength(int typeOrLength)
{
    handleChange();
    this->typeOrLength = typeOrLength;
}

int EthernetMacHeader::getHop_count() const
{
    return this->hop_count;
}

void EthernetMacHeader::setHop_count(int hop_count)
{
    handleChange();
    this->hop_count = hop_count;
}

bool EthernetMacHeader::isFB() const
{
    return this->isFB_;
}

void EthernetMacHeader::setIsFB(bool isFB)
{
    handleChange();
    this->isFB_ = isFB;
}

bool EthernetMacHeader::getAllow_same_input_output() const
{
    return this->allow_same_input_output;
}

void EthernetMacHeader::setAllow_same_input_output(bool allow_same_input_output)
{
    handleChange();
    this->allow_same_input_output = allow_same_input_output;
}

int EthernetMacHeader::getOriginal_interface_id() const
{
    return this->original_interface_id;
}

void EthernetMacHeader::setOriginal_interface_id(int original_interface_id)
{
    handleChange();
    this->original_interface_id = original_interface_id;
}

int EthernetMacHeader::getBouncedDistance() const
{
    return this->bouncedDistance;
}

void EthernetMacHeader::setBouncedDistance(int bouncedDistance)
{
    handleChange();
    this->bouncedDistance = bouncedDistance;
}

int EthernetMacHeader::getMaxBouncedDistance() const
{
    return this->maxBouncedDistance;
}

void EthernetMacHeader::setMaxBouncedDistance(int maxBouncedDistance)
{
    handleChange();
    this->maxBouncedDistance = maxBouncedDistance;
}

int EthernetMacHeader::getBouncedHop() const
{
    return this->bouncedHop;
}

void EthernetMacHeader::setBouncedHop(int bouncedHop)
{
    handleChange();
    this->bouncedHop = bouncedHop;
}

int EthernetMacHeader::getTotalHopNum() const
{
    return this->totalHopNum;
}

void EthernetMacHeader::setTotalHopNum(int totalHopNum)
{
    handleChange();
    this->totalHopNum = totalHopNum;
}

bool EthernetMacHeader::getIs_bursty() const
{
    return this->is_bursty;
}

void EthernetMacHeader::setIs_bursty(bool is_bursty)
{
    handleChange();
    this->is_bursty = is_bursty;
}

b EthernetMacHeader::getPayload_length() const
{
    return this->payload_length;
}

void EthernetMacHeader::setPayload_length(b payload_length)
{
    handleChange();
    this->payload_length = payload_length;
}

b EthernetMacHeader::getTotal_length() const
{
    return this->total_length;
}

void EthernetMacHeader::setTotal_length(b total_length)
{
    handleChange();
    this->total_length = total_length;
}

b EthernetMacHeader::getOffset() const
{
    return this->offset;
}

void EthernetMacHeader::setOffset(b offset)
{
    handleChange();
    this->offset = offset;
}

bool EthernetMacHeader::getIs_v2_dropped_packet_header() const
{
    return this->is_v2_dropped_packet_header;
}

void EthernetMacHeader::setIs_v2_dropped_packet_header(bool is_v2_dropped_packet_header)
{
    handleChange();
    this->is_v2_dropped_packet_header = is_v2_dropped_packet_header;
}

uint16_t EthernetMacHeader::getQueue_occupancy() const
{
    return this->queue_occupancy;
}

void EthernetMacHeader::setQueue_occupancy(uint16_t queue_occupancy)
{
    handleChange();
    this->queue_occupancy = queue_occupancy;
}

::omnetpp::simtime_t EthernetMacHeader::getTime_packet_received_at_nic() const
{
    return this->time_packet_received_at_nic;
}

void EthernetMacHeader::setTime_packet_received_at_nic(::omnetpp::simtime_t time_packet_received_at_nic)
{
    handleChange();
    this->time_packet_received_at_nic = time_packet_received_at_nic;
}

::omnetpp::simtime_t EthernetMacHeader::getLocal_nic_rx_delay() const
{
    return this->local_nic_rx_delay;
}

void EthernetMacHeader::setLocal_nic_rx_delay(::omnetpp::simtime_t local_nic_rx_delay)
{
    handleChange();
    this->local_nic_rx_delay = local_nic_rx_delay;
}

::omnetpp::simtime_t EthernetMacHeader::getRemote_queueing_time() const
{
    return this->remote_queueing_time;
}

void EthernetMacHeader::setRemote_queueing_time(::omnetpp::simtime_t remote_queueing_time)
{
    handleChange();
    this->remote_queueing_time = remote_queueing_time;
}

::omnetpp::simtime_t EthernetMacHeader::getFabric_delay_time_sent_from_source() const
{
    return this->fabric_delay_time_sent_from_source;
}

void EthernetMacHeader::setFabric_delay_time_sent_from_source(::omnetpp::simtime_t fabric_delay_time_sent_from_source)
{
    handleChange();
    this->fabric_delay_time_sent_from_source = fabric_delay_time_sent_from_source;
}

::omnetpp::simtime_t EthernetMacHeader::getTime_packet_sent_from_src() const
{
    return this->time_packet_sent_from_src;
}

void EthernetMacHeader::setTime_packet_sent_from_src(::omnetpp::simtime_t time_packet_sent_from_src)
{
    handleChange();
    this->time_packet_sent_from_src = time_packet_sent_from_src;
}

bool EthernetMacHeader::getIs_deflected() const
{
    return this->is_deflected;
}

void EthernetMacHeader::setIs_deflected(bool is_deflected)
{
    handleChange();
    this->is_deflected = is_deflected;
}

class EthernetMacHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_dest,
        FIELD_src,
        FIELD_cTag,
        FIELD_sTag,
        FIELD_typeOrLength,
        FIELD_hop_count,
        FIELD_isFB,
        FIELD_allow_same_input_output,
        FIELD_original_interface_id,
        FIELD_bouncedDistance,
        FIELD_maxBouncedDistance,
        FIELD_bouncedHop,
        FIELD_totalHopNum,
        FIELD_is_bursty,
        FIELD_payload_length,
        FIELD_total_length,
        FIELD_offset,
        FIELD_is_v2_dropped_packet_header,
        FIELD_queue_occupancy,
        FIELD_time_packet_received_at_nic,
        FIELD_local_nic_rx_delay,
        FIELD_remote_queueing_time,
        FIELD_fabric_delay_time_sent_from_source,
        FIELD_time_packet_sent_from_src,
        FIELD_is_deflected,
    };
  public:
    EthernetMacHeaderDescriptor();
    virtual ~EthernetMacHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EthernetMacHeaderDescriptor)

EthernetMacHeaderDescriptor::EthernetMacHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EthernetMacHeader)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EthernetMacHeaderDescriptor::~EthernetMacHeaderDescriptor()
{
    delete[] propertyNames;
}

bool EthernetMacHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetMacHeader *>(obj)!=nullptr;
}

const char **EthernetMacHeaderDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EthernetMacHeaderDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EthernetMacHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 25+base->getFieldCount() : 25;
}

unsigned int EthernetMacHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_dest
        0,    // FIELD_src
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISREPLACEABLE,    // FIELD_cTag
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISREPLACEABLE,    // FIELD_sTag
        FD_ISEDITABLE,    // FIELD_typeOrLength
        FD_ISEDITABLE,    // FIELD_hop_count
        FD_ISEDITABLE,    // FIELD_isFB
        FD_ISEDITABLE,    // FIELD_allow_same_input_output
        FD_ISEDITABLE,    // FIELD_original_interface_id
        FD_ISEDITABLE,    // FIELD_bouncedDistance
        FD_ISEDITABLE,    // FIELD_maxBouncedDistance
        FD_ISEDITABLE,    // FIELD_bouncedHop
        FD_ISEDITABLE,    // FIELD_totalHopNum
        FD_ISEDITABLE,    // FIELD_is_bursty
        FD_ISEDITABLE,    // FIELD_payload_length
        FD_ISEDITABLE,    // FIELD_total_length
        FD_ISEDITABLE,    // FIELD_offset
        FD_ISEDITABLE,    // FIELD_is_v2_dropped_packet_header
        FD_ISEDITABLE,    // FIELD_queue_occupancy
        FD_ISEDITABLE,    // FIELD_time_packet_received_at_nic
        FD_ISEDITABLE,    // FIELD_local_nic_rx_delay
        FD_ISEDITABLE,    // FIELD_remote_queueing_time
        FD_ISEDITABLE,    // FIELD_fabric_delay_time_sent_from_source
        FD_ISEDITABLE,    // FIELD_time_packet_sent_from_src
        FD_ISEDITABLE,    // FIELD_is_deflected
    };
    return (field >= 0 && field < 25) ? fieldTypeFlags[field] : 0;
}

const char *EthernetMacHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dest",
        "src",
        "cTag",
        "sTag",
        "typeOrLength",
        "hop_count",
        "isFB",
        "allow_same_input_output",
        "original_interface_id",
        "bouncedDistance",
        "maxBouncedDistance",
        "bouncedHop",
        "totalHopNum",
        "is_bursty",
        "payload_length",
        "total_length",
        "offset",
        "is_v2_dropped_packet_header",
        "queue_occupancy",
        "time_packet_received_at_nic",
        "local_nic_rx_delay",
        "remote_queueing_time",
        "fabric_delay_time_sent_from_source",
        "time_packet_sent_from_src",
        "is_deflected",
    };
    return (field >= 0 && field < 25) ? fieldNames[field] : nullptr;
}

int EthernetMacHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "dest") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "src") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "cTag") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sTag") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "typeOrLength") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "hop_count") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "isFB") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "allow_same_input_output") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "original_interface_id") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "bouncedDistance") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "maxBouncedDistance") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "bouncedHop") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "totalHopNum") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "is_bursty") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "payload_length") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "total_length") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "offset") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "is_v2_dropped_packet_header") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "queue_occupancy") == 0) return baseIndex + 18;
    if (strcmp(fieldName, "time_packet_received_at_nic") == 0) return baseIndex + 19;
    if (strcmp(fieldName, "local_nic_rx_delay") == 0) return baseIndex + 20;
    if (strcmp(fieldName, "remote_queueing_time") == 0) return baseIndex + 21;
    if (strcmp(fieldName, "fabric_delay_time_sent_from_source") == 0) return baseIndex + 22;
    if (strcmp(fieldName, "time_packet_sent_from_src") == 0) return baseIndex + 23;
    if (strcmp(fieldName, "is_deflected") == 0) return baseIndex + 24;
    return base ? base->findField(fieldName) : -1;
}

const char *EthernetMacHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_dest
        "inet::MacAddress",    // FIELD_src
        "inet::Ieee8021qHeader",    // FIELD_cTag
        "inet::Ieee8021qHeader",    // FIELD_sTag
        "int",    // FIELD_typeOrLength
        "int",    // FIELD_hop_count
        "bool",    // FIELD_isFB
        "bool",    // FIELD_allow_same_input_output
        "int",    // FIELD_original_interface_id
        "int",    // FIELD_bouncedDistance
        "int",    // FIELD_maxBouncedDistance
        "int",    // FIELD_bouncedHop
        "int",    // FIELD_totalHopNum
        "bool",    // FIELD_is_bursty
        "inet::b",    // FIELD_payload_length
        "inet::b",    // FIELD_total_length
        "inet::b",    // FIELD_offset
        "bool",    // FIELD_is_v2_dropped_packet_header
        "uint16_t",    // FIELD_queue_occupancy
        "omnetpp::simtime_t",    // FIELD_time_packet_received_at_nic
        "omnetpp::simtime_t",    // FIELD_local_nic_rx_delay
        "omnetpp::simtime_t",    // FIELD_remote_queueing_time
        "omnetpp::simtime_t",    // FIELD_fabric_delay_time_sent_from_source
        "omnetpp::simtime_t",    // FIELD_time_packet_sent_from_src
        "bool",    // FIELD_is_deflected
    };
    return (field >= 0 && field < 25) ? fieldTypeStrings[field] : nullptr;
}

const char **EthernetMacHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_cTag: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        case FIELD_sTag: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *EthernetMacHeaderDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_cTag:
            if (!strcmp(propertyName, "owned")) return "";
            return nullptr;
        case FIELD_sTag:
            if (!strcmp(propertyName, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int EthernetMacHeaderDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EthernetMacHeaderDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EthernetMacHeader'", field);
    }
}

const char *EthernetMacHeaderDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_cTag: { const Ieee8021qHeader * value = pp->getCTag(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_sTag: { const Ieee8021qHeader * value = pp->getSTag(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string EthernetMacHeaderDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_dest: return pp->getDest().str();
        case FIELD_src: return pp->getSrc().str();
        case FIELD_cTag: { auto obj = pp->getCTag(); return obj == nullptr ? "" : obj->str(); }
        case FIELD_sTag: { auto obj = pp->getSTag(); return obj == nullptr ? "" : obj->str(); }
        case FIELD_typeOrLength: return long2string(pp->getTypeOrLength());
        case FIELD_hop_count: return long2string(pp->getHop_count());
        case FIELD_isFB: return bool2string(pp->isFB());
        case FIELD_allow_same_input_output: return bool2string(pp->getAllow_same_input_output());
        case FIELD_original_interface_id: return long2string(pp->getOriginal_interface_id());
        case FIELD_bouncedDistance: return long2string(pp->getBouncedDistance());
        case FIELD_maxBouncedDistance: return long2string(pp->getMaxBouncedDistance());
        case FIELD_bouncedHop: return long2string(pp->getBouncedHop());
        case FIELD_totalHopNum: return long2string(pp->getTotalHopNum());
        case FIELD_is_bursty: return bool2string(pp->getIs_bursty());
        case FIELD_payload_length: return unit2string(pp->getPayload_length());
        case FIELD_total_length: return unit2string(pp->getTotal_length());
        case FIELD_offset: return unit2string(pp->getOffset());
        case FIELD_is_v2_dropped_packet_header: return bool2string(pp->getIs_v2_dropped_packet_header());
        case FIELD_queue_occupancy: return ulong2string(pp->getQueue_occupancy());
        case FIELD_time_packet_received_at_nic: return simtime2string(pp->getTime_packet_received_at_nic());
        case FIELD_local_nic_rx_delay: return simtime2string(pp->getLocal_nic_rx_delay());
        case FIELD_remote_queueing_time: return simtime2string(pp->getRemote_queueing_time());
        case FIELD_fabric_delay_time_sent_from_source: return simtime2string(pp->getFabric_delay_time_sent_from_source());
        case FIELD_time_packet_sent_from_src: return simtime2string(pp->getTime_packet_sent_from_src());
        case FIELD_is_deflected: return bool2string(pp->getIs_deflected());
        default: return "";
    }
}

void EthernetMacHeaderDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_typeOrLength: pp->setTypeOrLength(string2long(value)); break;
        case FIELD_hop_count: pp->setHop_count(string2long(value)); break;
        case FIELD_isFB: pp->setIsFB(string2bool(value)); break;
        case FIELD_allow_same_input_output: pp->setAllow_same_input_output(string2bool(value)); break;
        case FIELD_original_interface_id: pp->setOriginal_interface_id(string2long(value)); break;
        case FIELD_bouncedDistance: pp->setBouncedDistance(string2long(value)); break;
        case FIELD_maxBouncedDistance: pp->setMaxBouncedDistance(string2long(value)); break;
        case FIELD_bouncedHop: pp->setBouncedHop(string2long(value)); break;
        case FIELD_totalHopNum: pp->setTotalHopNum(string2long(value)); break;
        case FIELD_is_bursty: pp->setIs_bursty(string2bool(value)); break;
        case FIELD_payload_length: pp->setPayload_length(b(string2long(value))); break;
        case FIELD_total_length: pp->setTotal_length(b(string2long(value))); break;
        case FIELD_offset: pp->setOffset(b(string2long(value))); break;
        case FIELD_is_v2_dropped_packet_header: pp->setIs_v2_dropped_packet_header(string2bool(value)); break;
        case FIELD_queue_occupancy: pp->setQueue_occupancy(string2ulong(value)); break;
        case FIELD_time_packet_received_at_nic: pp->setTime_packet_received_at_nic(string2simtime(value)); break;
        case FIELD_local_nic_rx_delay: pp->setLocal_nic_rx_delay(string2simtime(value)); break;
        case FIELD_remote_queueing_time: pp->setRemote_queueing_time(string2simtime(value)); break;
        case FIELD_fabric_delay_time_sent_from_source: pp->setFabric_delay_time_sent_from_source(string2simtime(value)); break;
        case FIELD_time_packet_sent_from_src: pp->setTime_packet_sent_from_src(string2simtime(value)); break;
        case FIELD_is_deflected: pp->setIs_deflected(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetMacHeader'", field);
    }
}

omnetpp::cValue EthernetMacHeaderDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_dest: return omnetpp::toAnyPtr(&pp->getDest()); break;
        case FIELD_src: return omnetpp::toAnyPtr(&pp->getSrc()); break;
        case FIELD_cTag: return omnetpp::toAnyPtr(pp->getCTag()); break;
        case FIELD_sTag: return omnetpp::toAnyPtr(pp->getSTag()); break;
        case FIELD_typeOrLength: return pp->getTypeOrLength();
        case FIELD_hop_count: return pp->getHop_count();
        case FIELD_isFB: return pp->isFB();
        case FIELD_allow_same_input_output: return pp->getAllow_same_input_output();
        case FIELD_original_interface_id: return pp->getOriginal_interface_id();
        case FIELD_bouncedDistance: return pp->getBouncedDistance();
        case FIELD_maxBouncedDistance: return pp->getMaxBouncedDistance();
        case FIELD_bouncedHop: return pp->getBouncedHop();
        case FIELD_totalHopNum: return pp->getTotalHopNum();
        case FIELD_is_bursty: return pp->getIs_bursty();
        case FIELD_payload_length: throw omnetpp::cRuntimeError("Cannot return field 'inet::EthernetMacHeader::payload_length' (type 'b') as cValue, please provide @toValue in the msg file");
        case FIELD_total_length: throw omnetpp::cRuntimeError("Cannot return field 'inet::EthernetMacHeader::total_length' (type 'b') as cValue, please provide @toValue in the msg file");
        case FIELD_offset: throw omnetpp::cRuntimeError("Cannot return field 'inet::EthernetMacHeader::offset' (type 'b') as cValue, please provide @toValue in the msg file");
        case FIELD_is_v2_dropped_packet_header: return pp->getIs_v2_dropped_packet_header();
        case FIELD_queue_occupancy: return (omnetpp::intval_t)(pp->getQueue_occupancy());
        case FIELD_time_packet_received_at_nic: return pp->getTime_packet_received_at_nic().dbl();
        case FIELD_local_nic_rx_delay: return pp->getLocal_nic_rx_delay().dbl();
        case FIELD_remote_queueing_time: return pp->getRemote_queueing_time().dbl();
        case FIELD_fabric_delay_time_sent_from_source: return pp->getFabric_delay_time_sent_from_source().dbl();
        case FIELD_time_packet_sent_from_src: return pp->getTime_packet_sent_from_src().dbl();
        case FIELD_is_deflected: return pp->getIs_deflected();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EthernetMacHeader' as cValue -- field index out of range?", field);
    }
}

void EthernetMacHeaderDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_cTag: pp->setCTag(omnetpp::fromAnyPtr<Ieee8021qHeader>(value.pointerValue())); break;
        case FIELD_sTag: pp->setSTag(omnetpp::fromAnyPtr<Ieee8021qHeader>(value.pointerValue())); break;
        case FIELD_typeOrLength: pp->setTypeOrLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_hop_count: pp->setHop_count(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isFB: pp->setIsFB(value.boolValue()); break;
        case FIELD_allow_same_input_output: pp->setAllow_same_input_output(value.boolValue()); break;
        case FIELD_original_interface_id: pp->setOriginal_interface_id(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bouncedDistance: pp->setBouncedDistance(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_maxBouncedDistance: pp->setMaxBouncedDistance(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bouncedHop: pp->setBouncedHop(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_totalHopNum: pp->setTotalHopNum(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_is_bursty: pp->setIs_bursty(value.boolValue()); break;
        case FIELD_payload_length: throw omnetpp::cRuntimeError("Cannot set field 'inet::EthernetMacHeader::payload_length' (type 'b') from cValue, please provide @fromValue in the msg file");
        case FIELD_total_length: throw omnetpp::cRuntimeError("Cannot set field 'inet::EthernetMacHeader::total_length' (type 'b') from cValue, please provide @fromValue in the msg file");
        case FIELD_offset: throw omnetpp::cRuntimeError("Cannot set field 'inet::EthernetMacHeader::offset' (type 'b') from cValue, please provide @fromValue in the msg file");
        case FIELD_is_v2_dropped_packet_header: pp->setIs_v2_dropped_packet_header(value.boolValue()); break;
        case FIELD_queue_occupancy: pp->setQueue_occupancy(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_time_packet_received_at_nic: pp->setTime_packet_received_at_nic(value.doubleValue()); break;
        case FIELD_local_nic_rx_delay: pp->setLocal_nic_rx_delay(value.doubleValue()); break;
        case FIELD_remote_queueing_time: pp->setRemote_queueing_time(value.doubleValue()); break;
        case FIELD_fabric_delay_time_sent_from_source: pp->setFabric_delay_time_sent_from_source(value.doubleValue()); break;
        case FIELD_time_packet_sent_from_src: pp->setTime_packet_sent_from_src(value.doubleValue()); break;
        case FIELD_is_deflected: pp->setIs_deflected(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetMacHeader'", field);
    }
}

const char *EthernetMacHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_cTag: return omnetpp::opp_typename(typeid(Ieee8021qHeader));
        case FIELD_sTag: return omnetpp::opp_typename(typeid(Ieee8021qHeader));
        default: return nullptr;
    };
}

omnetpp::any_ptr EthernetMacHeaderDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_dest: return omnetpp::toAnyPtr(&pp->getDest()); break;
        case FIELD_src: return omnetpp::toAnyPtr(&pp->getSrc()); break;
        case FIELD_cTag: return omnetpp::toAnyPtr(pp->getCTag()); break;
        case FIELD_sTag: return omnetpp::toAnyPtr(pp->getSTag()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EthernetMacHeaderDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetMacHeader *pp = omnetpp::fromAnyPtr<EthernetMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_cTag: pp->setCTag(omnetpp::fromAnyPtr<Ieee8021qHeader>(ptr)); break;
        case FIELD_sTag: pp->setSTag(omnetpp::fromAnyPtr<Ieee8021qHeader>(ptr)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetMacHeader'", field);
    }
}

Register_Class(EthernetControlFrame)

EthernetControlFrame::EthernetControlFrame() : ::inet::FieldsChunk()
{
}

EthernetControlFrame::EthernetControlFrame(const EthernetControlFrame& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EthernetControlFrame::~EthernetControlFrame()
{
}

EthernetControlFrame& EthernetControlFrame::operator=(const EthernetControlFrame& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EthernetControlFrame::copy(const EthernetControlFrame& other)
{
    this->opCode = other.opCode;
}

void EthernetControlFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->opCode);
}

void EthernetControlFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->opCode);
}

int EthernetControlFrame::getOpCode() const
{
    return this->opCode;
}

void EthernetControlFrame::setOpCode(int opCode)
{
    handleChange();
    this->opCode = opCode;
}

class EthernetControlFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_opCode,
    };
  public:
    EthernetControlFrameDescriptor();
    virtual ~EthernetControlFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EthernetControlFrameDescriptor)

EthernetControlFrameDescriptor::EthernetControlFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EthernetControlFrame)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EthernetControlFrameDescriptor::~EthernetControlFrameDescriptor()
{
    delete[] propertyNames;
}

bool EthernetControlFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetControlFrame *>(obj)!=nullptr;
}

const char **EthernetControlFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EthernetControlFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EthernetControlFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int EthernetControlFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_opCode
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *EthernetControlFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "opCode",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int EthernetControlFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "opCode") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *EthernetControlFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_opCode
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **EthernetControlFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EthernetControlFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EthernetControlFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EthernetControlFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EthernetControlFrame'", field);
    }
}

const char *EthernetControlFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthernetControlFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        case FIELD_opCode: return long2string(pp->getOpCode());
        default: return "";
    }
}

void EthernetControlFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        case FIELD_opCode: pp->setOpCode(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetControlFrame'", field);
    }
}

omnetpp::cValue EthernetControlFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        case FIELD_opCode: return pp->getOpCode();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EthernetControlFrame' as cValue -- field index out of range?", field);
    }
}

void EthernetControlFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        case FIELD_opCode: pp->setOpCode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetControlFrame'", field);
    }
}

const char *EthernetControlFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr EthernetControlFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EthernetControlFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetControlFrame *pp = omnetpp::fromAnyPtr<EthernetControlFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetControlFrame'", field);
    }
}

Register_Class(EthernetPauseFrame)

EthernetPauseFrame::EthernetPauseFrame() : ::inet::EthernetControlFrame()
{
    this->setChunkLength(ETHER_PAUSE_COMMAND_BYTES);
    this->setOpCode(ETHERNET_CONTROL_PAUSE);

}

EthernetPauseFrame::EthernetPauseFrame(const EthernetPauseFrame& other) : ::inet::EthernetControlFrame(other)
{
    copy(other);
}

EthernetPauseFrame::~EthernetPauseFrame()
{
}

EthernetPauseFrame& EthernetPauseFrame::operator=(const EthernetPauseFrame& other)
{
    if (this == &other) return *this;
    ::inet::EthernetControlFrame::operator=(other);
    copy(other);
    return *this;
}

void EthernetPauseFrame::copy(const EthernetPauseFrame& other)
{
    this->pauseTime = other.pauseTime;
}

void EthernetPauseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EthernetControlFrame::parsimPack(b);
    doParsimPacking(b,this->pauseTime);
}

void EthernetPauseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EthernetControlFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->pauseTime);
}

int EthernetPauseFrame::getPauseTime() const
{
    return this->pauseTime;
}

void EthernetPauseFrame::setPauseTime(int pauseTime)
{
    handleChange();
    this->pauseTime = pauseTime;
}

class EthernetPauseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_pauseTime,
    };
  public:
    EthernetPauseFrameDescriptor();
    virtual ~EthernetPauseFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EthernetPauseFrameDescriptor)

EthernetPauseFrameDescriptor::EthernetPauseFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EthernetPauseFrame)), "inet::EthernetControlFrame")
{
    propertyNames = nullptr;
}

EthernetPauseFrameDescriptor::~EthernetPauseFrameDescriptor()
{
    delete[] propertyNames;
}

bool EthernetPauseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetPauseFrame *>(obj)!=nullptr;
}

const char **EthernetPauseFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EthernetPauseFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EthernetPauseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int EthernetPauseFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_pauseTime
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *EthernetPauseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "pauseTime",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int EthernetPauseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "pauseTime") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *EthernetPauseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_pauseTime
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **EthernetPauseFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EthernetPauseFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EthernetPauseFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EthernetPauseFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EthernetPauseFrame'", field);
    }
}

const char *EthernetPauseFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthernetPauseFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pauseTime: return long2string(pp->getPauseTime());
        default: return "";
    }
}

void EthernetPauseFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pauseTime: pp->setPauseTime(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetPauseFrame'", field);
    }
}

omnetpp::cValue EthernetPauseFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pauseTime: return pp->getPauseTime();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EthernetPauseFrame' as cValue -- field index out of range?", field);
    }
}

void EthernetPauseFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pauseTime: pp->setPauseTime(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetPauseFrame'", field);
    }
}

const char *EthernetPauseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr EthernetPauseFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EthernetPauseFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPauseFrame *pp = omnetpp::fromAnyPtr<EthernetPauseFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetPauseFrame'", field);
    }
}

Register_Class(EthernetPadding)

EthernetPadding::EthernetPadding() : ::inet::FieldsChunk()
{
}

EthernetPadding::EthernetPadding(const EthernetPadding& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EthernetPadding::~EthernetPadding()
{
}

EthernetPadding& EthernetPadding::operator=(const EthernetPadding& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EthernetPadding::copy(const EthernetPadding& other)
{
}

void EthernetPadding::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
}

void EthernetPadding::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
}

class EthernetPaddingDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    EthernetPaddingDescriptor();
    virtual ~EthernetPaddingDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EthernetPaddingDescriptor)

EthernetPaddingDescriptor::EthernetPaddingDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EthernetPadding)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EthernetPaddingDescriptor::~EthernetPaddingDescriptor()
{
    delete[] propertyNames;
}

bool EthernetPaddingDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetPadding *>(obj)!=nullptr;
}

const char **EthernetPaddingDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EthernetPaddingDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EthernetPaddingDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int EthernetPaddingDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *EthernetPaddingDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int EthernetPaddingDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *EthernetPaddingDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **EthernetPaddingDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EthernetPaddingDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EthernetPaddingDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EthernetPaddingDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EthernetPadding'", field);
    }
}

const char *EthernetPaddingDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthernetPaddingDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void EthernetPaddingDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetPadding'", field);
    }
}

omnetpp::cValue EthernetPaddingDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EthernetPadding' as cValue -- field index out of range?", field);
    }
}

void EthernetPaddingDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetPadding'", field);
    }
}

const char *EthernetPaddingDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr EthernetPaddingDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EthernetPaddingDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetPadding *pp = omnetpp::fromAnyPtr<EthernetPadding>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetPadding'", field);
    }
}

Register_Class(EthernetFcs)

EthernetFcs::EthernetFcs() : ::inet::FieldsChunk()
{
    this->setChunkLength(ETHER_FCS_BYTES);

}

EthernetFcs::EthernetFcs(const EthernetFcs& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EthernetFcs::~EthernetFcs()
{
}

EthernetFcs& EthernetFcs::operator=(const EthernetFcs& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EthernetFcs::copy(const EthernetFcs& other)
{
    this->fcs = other.fcs;
    this->fcsMode = other.fcsMode;
}

void EthernetFcs::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->fcs);
    doParsimPacking(b,this->fcsMode);
}

void EthernetFcs::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->fcs);
    doParsimUnpacking(b,this->fcsMode);
}

uint32_t EthernetFcs::getFcs() const
{
    return this->fcs;
}

void EthernetFcs::setFcs(uint32_t fcs)
{
    handleChange();
    this->fcs = fcs;
}

FcsMode EthernetFcs::getFcsMode() const
{
    return this->fcsMode;
}

void EthernetFcs::setFcsMode(FcsMode fcsMode)
{
    handleChange();
    this->fcsMode = fcsMode;
}

class EthernetFcsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_fcs,
        FIELD_fcsMode,
    };
  public:
    EthernetFcsDescriptor();
    virtual ~EthernetFcsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EthernetFcsDescriptor)

EthernetFcsDescriptor::EthernetFcsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EthernetFcs)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EthernetFcsDescriptor::~EthernetFcsDescriptor()
{
    delete[] propertyNames;
}

bool EthernetFcsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetFcs *>(obj)!=nullptr;
}

const char **EthernetFcsDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EthernetFcsDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EthernetFcsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int EthernetFcsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fcs
        0,    // FIELD_fcsMode
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *EthernetFcsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fcs",
        "fcsMode",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int EthernetFcsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "fcs") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "fcsMode") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *EthernetFcsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_fcs
        "inet::FcsMode",    // FIELD_fcsMode
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **EthernetFcsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_fcsMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *EthernetFcsDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_fcsMode:
            if (!strcmp(propertyName, "enum")) return "inet::FcsMode";
            return nullptr;
        default: return nullptr;
    }
}

int EthernetFcsDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EthernetFcsDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EthernetFcs'", field);
    }
}

const char *EthernetFcsDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthernetFcsDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        case FIELD_fcs: return ulong2string(pp->getFcs());
        case FIELD_fcsMode: return enum2string(pp->getFcsMode(), "inet::FcsMode");
        default: return "";
    }
}

void EthernetFcsDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        case FIELD_fcs: pp->setFcs(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetFcs'", field);
    }
}

omnetpp::cValue EthernetFcsDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        case FIELD_fcs: return (omnetpp::intval_t)(pp->getFcs());
        case FIELD_fcsMode: return static_cast<int>(pp->getFcsMode());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EthernetFcs' as cValue -- field index out of range?", field);
    }
}

void EthernetFcsDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        case FIELD_fcs: pp->setFcs(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetFcs'", field);
    }
}

const char *EthernetFcsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr EthernetFcsDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EthernetFcsDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetFcs *pp = omnetpp::fromAnyPtr<EthernetFcs>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetFcs'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

