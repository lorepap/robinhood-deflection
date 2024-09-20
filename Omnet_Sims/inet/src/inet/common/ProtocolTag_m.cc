//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/common/ProtocolTag.msg.
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
#include "ProtocolTag_m.h"

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

class ChunkPtrDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_content,
    };
  public:
    ChunkPtrDescriptor();
    virtual ~ChunkPtrDescriptor();

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

Register_ClassDescriptor(ChunkPtrDescriptor)

ChunkPtrDescriptor::ChunkPtrDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ChunkPtr)), "")
{
    propertyNames = nullptr;
}

ChunkPtrDescriptor::~ChunkPtrDescriptor()
{
    delete[] propertyNames;
}

bool ChunkPtrDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ChunkPtr *>(obj)!=nullptr;
}

const char **ChunkPtrDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ChunkPtrDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "existingClass")) return "";
    if (!strcmp(propertyName, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ChunkPtrDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int ChunkPtrDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_content
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *ChunkPtrDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "content",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int ChunkPtrDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "content") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *ChunkPtrDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Chunk",    // FIELD_content
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **ChunkPtrDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_content: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *ChunkPtrDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_content:
            if (!strcmp(propertyName, "getter")) return "get";
            return nullptr;
        default: return nullptr;
    }
}

int ChunkPtrDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ChunkPtrDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ChunkPtr'", field);
    }
}

const char *ChunkPtrDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        case FIELD_content: { const Chunk * value = pp->get(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string ChunkPtrDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        case FIELD_content: { auto obj = pp->get(); return obj == nullptr ? "" : obj->str(); }
        default: return "";
    }
}

void ChunkPtrDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ChunkPtr'", field);
    }
}

omnetpp::cValue ChunkPtrDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        case FIELD_content: return omnetpp::toAnyPtr(pp->get()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ChunkPtr' as cValue -- field index out of range?", field);
    }
}

void ChunkPtrDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ChunkPtr'", field);
    }
}

const char *ChunkPtrDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_content: return omnetpp::opp_typename(typeid(Chunk));
        default: return nullptr;
    };
}

omnetpp::any_ptr ChunkPtrDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        case FIELD_content: return omnetpp::toAnyPtr(pp->get()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ChunkPtrDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ChunkPtr *pp = omnetpp::fromAnyPtr<ChunkPtr>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ChunkPtr'", field);
    }
}

Register_Class(ProtocolTagBase)

ProtocolTagBase::ProtocolTagBase() : ::inet::TagBase()
{
}

ProtocolTagBase::ProtocolTagBase(const ProtocolTagBase& other) : ::inet::TagBase(other)
{
    copy(other);
}

ProtocolTagBase::~ProtocolTagBase()
{
}

ProtocolTagBase& ProtocolTagBase::operator=(const ProtocolTagBase& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void ProtocolTagBase::copy(const ProtocolTagBase& other)
{
    this->protocol = other.protocol;
}

void ProtocolTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->protocol);
}

void ProtocolTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->protocol);
}

const Protocol * ProtocolTagBase::getProtocol() const
{
    return this->protocol;
}

void ProtocolTagBase::setProtocol(const Protocol * protocol)
{
    this->protocol = protocol;
}

class ProtocolTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_protocol,
    };
  public:
    ProtocolTagBaseDescriptor();
    virtual ~ProtocolTagBaseDescriptor();

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

Register_ClassDescriptor(ProtocolTagBaseDescriptor)

ProtocolTagBaseDescriptor::ProtocolTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ProtocolTagBase)), "inet::TagBase")
{
    propertyNames = nullptr;
}

ProtocolTagBaseDescriptor::~ProtocolTagBaseDescriptor()
{
    delete[] propertyNames;
}

bool ProtocolTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ProtocolTagBase *>(obj)!=nullptr;
}

const char **ProtocolTagBaseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ProtocolTagBaseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ProtocolTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int ProtocolTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_protocol
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *ProtocolTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "protocol",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int ProtocolTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "protocol") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *ProtocolTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Protocol",    // FIELD_protocol
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **ProtocolTagBaseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_protocol: {
            static const char *names[] = { "toString",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *ProtocolTagBaseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_protocol:
            if (!strcmp(propertyName, "toString")) return "->str()";
            return nullptr;
        default: return nullptr;
    }
}

int ProtocolTagBaseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ProtocolTagBaseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ProtocolTagBase'", field);
    }
}

const char *ProtocolTagBaseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        case FIELD_protocol: { const Protocol * value = pp->getProtocol(); return omnetpp::opp_typename(typeid(*const_cast<Protocol *>(value))); }
        default: return nullptr;
    }
}

std::string ProtocolTagBaseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        case FIELD_protocol: { auto obj = pp->getProtocol(); return obj == nullptr ? "" : obj->str(); }
        default: return "";
    }
}

void ProtocolTagBaseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ProtocolTagBase'", field);
    }
}

omnetpp::cValue ProtocolTagBaseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        case FIELD_protocol: return omnetpp::toAnyPtr(pp->getProtocol()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ProtocolTagBase' as cValue -- field index out of range?", field);
    }
}

void ProtocolTagBaseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ProtocolTagBase'", field);
    }
}

const char *ProtocolTagBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_protocol: return omnetpp::opp_typename(typeid(Protocol));
        default: return nullptr;
    };
}

omnetpp::any_ptr ProtocolTagBaseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        case FIELD_protocol: return omnetpp::toAnyPtr(pp->getProtocol()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ProtocolTagBaseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ProtocolTagBase *pp = omnetpp::fromAnyPtr<ProtocolTagBase>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ProtocolTagBase'", field);
    }
}

Register_Enum(inet::ServicePrimitive, (inet::ServicePrimitive::SP_REQUEST, inet::ServicePrimitive::SP_INDICATION, inet::ServicePrimitive::SP_RESPONSE, inet::ServicePrimitive::SP_CONFIRM));

Register_Class(DispatchProtocolReq)

DispatchProtocolReq::DispatchProtocolReq() : ::inet::ProtocolTagBase()
{
}

DispatchProtocolReq::DispatchProtocolReq(const DispatchProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

DispatchProtocolReq::~DispatchProtocolReq()
{
}

DispatchProtocolReq& DispatchProtocolReq::operator=(const DispatchProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void DispatchProtocolReq::copy(const DispatchProtocolReq& other)
{
    this->servicePrimitive = other.servicePrimitive;
}

void DispatchProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->servicePrimitive);
}

void DispatchProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->servicePrimitive);
}

ServicePrimitive DispatchProtocolReq::getServicePrimitive() const
{
    return this->servicePrimitive;
}

void DispatchProtocolReq::setServicePrimitive(ServicePrimitive servicePrimitive)
{
    this->servicePrimitive = servicePrimitive;
}

class DispatchProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_servicePrimitive,
    };
  public:
    DispatchProtocolReqDescriptor();
    virtual ~DispatchProtocolReqDescriptor();

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

Register_ClassDescriptor(DispatchProtocolReqDescriptor)

DispatchProtocolReqDescriptor::DispatchProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DispatchProtocolReq)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

DispatchProtocolReqDescriptor::~DispatchProtocolReqDescriptor()
{
    delete[] propertyNames;
}

bool DispatchProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DispatchProtocolReq *>(obj)!=nullptr;
}

const char **DispatchProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DispatchProtocolReqDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DispatchProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int DispatchProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_servicePrimitive
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DispatchProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "servicePrimitive",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DispatchProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "servicePrimitive") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *DispatchProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ServicePrimitive",    // FIELD_servicePrimitive
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DispatchProtocolReqDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_servicePrimitive: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *DispatchProtocolReqDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_servicePrimitive:
            if (!strcmp(propertyName, "enum")) return "inet::ServicePrimitive";
            return nullptr;
        default: return nullptr;
    }
}

int DispatchProtocolReqDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DispatchProtocolReqDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DispatchProtocolReq'", field);
    }
}

const char *DispatchProtocolReqDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DispatchProtocolReqDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        case FIELD_servicePrimitive: return enum2string(pp->getServicePrimitive(), "inet::ServicePrimitive");
        default: return "";
    }
}

void DispatchProtocolReqDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DispatchProtocolReq'", field);
    }
}

omnetpp::cValue DispatchProtocolReqDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        case FIELD_servicePrimitive: return static_cast<int>(pp->getServicePrimitive());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DispatchProtocolReq' as cValue -- field index out of range?", field);
    }
}

void DispatchProtocolReqDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DispatchProtocolReq'", field);
    }
}

const char *DispatchProtocolReqDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DispatchProtocolReqDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DispatchProtocolReqDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolReq *pp = omnetpp::fromAnyPtr<DispatchProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DispatchProtocolReq'", field);
    }
}

Register_Class(DispatchProtocolInd)

DispatchProtocolInd::DispatchProtocolInd() : ::inet::ProtocolTagBase()
{
}

DispatchProtocolInd::DispatchProtocolInd(const DispatchProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

DispatchProtocolInd::~DispatchProtocolInd()
{
}

DispatchProtocolInd& DispatchProtocolInd::operator=(const DispatchProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void DispatchProtocolInd::copy(const DispatchProtocolInd& other)
{
}

void DispatchProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void DispatchProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class DispatchProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    DispatchProtocolIndDescriptor();
    virtual ~DispatchProtocolIndDescriptor();

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

Register_ClassDescriptor(DispatchProtocolIndDescriptor)

DispatchProtocolIndDescriptor::DispatchProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DispatchProtocolInd)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

DispatchProtocolIndDescriptor::~DispatchProtocolIndDescriptor()
{
    delete[] propertyNames;
}

bool DispatchProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DispatchProtocolInd *>(obj)!=nullptr;
}

const char **DispatchProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DispatchProtocolIndDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DispatchProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int DispatchProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *DispatchProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int DispatchProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *DispatchProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **DispatchProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *DispatchProtocolIndDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DispatchProtocolIndDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DispatchProtocolIndDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DispatchProtocolInd'", field);
    }
}

const char *DispatchProtocolIndDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DispatchProtocolIndDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void DispatchProtocolIndDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DispatchProtocolInd'", field);
    }
}

omnetpp::cValue DispatchProtocolIndDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DispatchProtocolInd' as cValue -- field index out of range?", field);
    }
}

void DispatchProtocolIndDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DispatchProtocolInd'", field);
    }
}

const char *DispatchProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr DispatchProtocolIndDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DispatchProtocolIndDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DispatchProtocolInd *pp = omnetpp::fromAnyPtr<DispatchProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DispatchProtocolInd'", field);
    }
}

Register_Class(PacketProtocolTag)

PacketProtocolTag::PacketProtocolTag() : ::inet::ProtocolTagBase()
{
}

PacketProtocolTag::PacketProtocolTag(const PacketProtocolTag& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

PacketProtocolTag::~PacketProtocolTag()
{
}

PacketProtocolTag& PacketProtocolTag::operator=(const PacketProtocolTag& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void PacketProtocolTag::copy(const PacketProtocolTag& other)
{
}

void PacketProtocolTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void PacketProtocolTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class PacketProtocolTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    PacketProtocolTagDescriptor();
    virtual ~PacketProtocolTagDescriptor();

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

Register_ClassDescriptor(PacketProtocolTagDescriptor)

PacketProtocolTagDescriptor::PacketProtocolTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PacketProtocolTag)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

PacketProtocolTagDescriptor::~PacketProtocolTagDescriptor()
{
    delete[] propertyNames;
}

bool PacketProtocolTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketProtocolTag *>(obj)!=nullptr;
}

const char **PacketProtocolTagDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PacketProtocolTagDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PacketProtocolTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int PacketProtocolTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *PacketProtocolTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int PacketProtocolTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *PacketProtocolTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **PacketProtocolTagDescriptor::getFieldPropertyNames(int field) const
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

const char *PacketProtocolTagDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PacketProtocolTagDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacketProtocolTagDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketProtocolTag'", field);
    }
}

const char *PacketProtocolTagDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PacketProtocolTagDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void PacketProtocolTagDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketProtocolTag'", field);
    }
}

omnetpp::cValue PacketProtocolTagDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PacketProtocolTag' as cValue -- field index out of range?", field);
    }
}

void PacketProtocolTagDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketProtocolTag'", field);
    }
}

const char *PacketProtocolTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr PacketProtocolTagDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PacketProtocolTagDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketProtocolTag *pp = omnetpp::fromAnyPtr<PacketProtocolTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketProtocolTag'", field);
    }
}

Register_Class(TransportProtocolReq)

TransportProtocolReq::TransportProtocolReq() : ::inet::ProtocolTagBase()
{
}

TransportProtocolReq::TransportProtocolReq(const TransportProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

TransportProtocolReq::~TransportProtocolReq()
{
}

TransportProtocolReq& TransportProtocolReq::operator=(const TransportProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void TransportProtocolReq::copy(const TransportProtocolReq& other)
{
}

void TransportProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void TransportProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class TransportProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    TransportProtocolReqDescriptor();
    virtual ~TransportProtocolReqDescriptor();

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

Register_ClassDescriptor(TransportProtocolReqDescriptor)

TransportProtocolReqDescriptor::TransportProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TransportProtocolReq)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

TransportProtocolReqDescriptor::~TransportProtocolReqDescriptor()
{
    delete[] propertyNames;
}

bool TransportProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransportProtocolReq *>(obj)!=nullptr;
}

const char **TransportProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TransportProtocolReqDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TransportProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int TransportProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *TransportProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int TransportProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *TransportProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **TransportProtocolReqDescriptor::getFieldPropertyNames(int field) const
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

const char *TransportProtocolReqDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int TransportProtocolReqDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TransportProtocolReqDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TransportProtocolReq'", field);
    }
}

const char *TransportProtocolReqDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransportProtocolReqDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void TransportProtocolReqDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransportProtocolReq'", field);
    }
}

omnetpp::cValue TransportProtocolReqDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TransportProtocolReq' as cValue -- field index out of range?", field);
    }
}

void TransportProtocolReqDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransportProtocolReq'", field);
    }
}

const char *TransportProtocolReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr TransportProtocolReqDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TransportProtocolReqDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolReq *pp = omnetpp::fromAnyPtr<TransportProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransportProtocolReq'", field);
    }
}

Register_Class(TransportProtocolInd)

TransportProtocolInd::TransportProtocolInd() : ::inet::ProtocolTagBase()
{
}

TransportProtocolInd::TransportProtocolInd(const TransportProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

TransportProtocolInd::~TransportProtocolInd()
{
}

TransportProtocolInd& TransportProtocolInd::operator=(const TransportProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void TransportProtocolInd::copy(const TransportProtocolInd& other)
{
    this->transportProtocolHeader = other.transportProtocolHeader;
}

void TransportProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->transportProtocolHeader);
}

void TransportProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->transportProtocolHeader);
}

const ChunkPtr& TransportProtocolInd::getTransportProtocolHeader() const
{
    return this->transportProtocolHeader;
}

void TransportProtocolInd::setTransportProtocolHeader(const ChunkPtr& transportProtocolHeader)
{
    this->transportProtocolHeader = transportProtocolHeader;
}

class TransportProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_transportProtocolHeader,
    };
  public:
    TransportProtocolIndDescriptor();
    virtual ~TransportProtocolIndDescriptor();

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

Register_ClassDescriptor(TransportProtocolIndDescriptor)

TransportProtocolIndDescriptor::TransportProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TransportProtocolInd)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

TransportProtocolIndDescriptor::~TransportProtocolIndDescriptor()
{
    delete[] propertyNames;
}

bool TransportProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransportProtocolInd *>(obj)!=nullptr;
}

const char **TransportProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TransportProtocolIndDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TransportProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int TransportProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_transportProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TransportProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transportProtocolHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TransportProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "transportProtocolHeader") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *TransportProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkPtr",    // FIELD_transportProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TransportProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *TransportProtocolIndDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int TransportProtocolIndDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TransportProtocolIndDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TransportProtocolInd'", field);
    }
}

const char *TransportProtocolIndDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransportProtocolIndDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_transportProtocolHeader: return "";
        default: return "";
    }
}

void TransportProtocolIndDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransportProtocolInd'", field);
    }
}

omnetpp::cValue TransportProtocolIndDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_transportProtocolHeader: return omnetpp::toAnyPtr(&pp->getTransportProtocolHeader()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TransportProtocolInd' as cValue -- field index out of range?", field);
    }
}

void TransportProtocolIndDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransportProtocolInd'", field);
    }
}

const char *TransportProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_transportProtocolHeader: return omnetpp::opp_typename(typeid(ChunkPtr));
        default: return nullptr;
    };
}

omnetpp::any_ptr TransportProtocolIndDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_transportProtocolHeader: return omnetpp::toAnyPtr(&pp->getTransportProtocolHeader()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TransportProtocolIndDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TransportProtocolInd *pp = omnetpp::fromAnyPtr<TransportProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransportProtocolInd'", field);
    }
}

Register_Class(NetworkProtocolReq)

NetworkProtocolReq::NetworkProtocolReq() : ::inet::ProtocolTagBase()
{
}

NetworkProtocolReq::NetworkProtocolReq(const NetworkProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

NetworkProtocolReq::~NetworkProtocolReq()
{
}

NetworkProtocolReq& NetworkProtocolReq::operator=(const NetworkProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void NetworkProtocolReq::copy(const NetworkProtocolReq& other)
{
}

void NetworkProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void NetworkProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class NetworkProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    NetworkProtocolReqDescriptor();
    virtual ~NetworkProtocolReqDescriptor();

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

Register_ClassDescriptor(NetworkProtocolReqDescriptor)

NetworkProtocolReqDescriptor::NetworkProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::NetworkProtocolReq)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

NetworkProtocolReqDescriptor::~NetworkProtocolReqDescriptor()
{
    delete[] propertyNames;
}

bool NetworkProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetworkProtocolReq *>(obj)!=nullptr;
}

const char **NetworkProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NetworkProtocolReqDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NetworkProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int NetworkProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *NetworkProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int NetworkProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *NetworkProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **NetworkProtocolReqDescriptor::getFieldPropertyNames(int field) const
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

const char *NetworkProtocolReqDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int NetworkProtocolReqDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NetworkProtocolReqDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NetworkProtocolReq'", field);
    }
}

const char *NetworkProtocolReqDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetworkProtocolReqDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void NetworkProtocolReqDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NetworkProtocolReq'", field);
    }
}

omnetpp::cValue NetworkProtocolReqDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NetworkProtocolReq' as cValue -- field index out of range?", field);
    }
}

void NetworkProtocolReqDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NetworkProtocolReq'", field);
    }
}

const char *NetworkProtocolReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr NetworkProtocolReqDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NetworkProtocolReqDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolReq *pp = omnetpp::fromAnyPtr<NetworkProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NetworkProtocolReq'", field);
    }
}

Register_Class(NetworkProtocolInd)

NetworkProtocolInd::NetworkProtocolInd() : ::inet::ProtocolTagBase()
{
}

NetworkProtocolInd::NetworkProtocolInd(const NetworkProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

NetworkProtocolInd::~NetworkProtocolInd()
{
}

NetworkProtocolInd& NetworkProtocolInd::operator=(const NetworkProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void NetworkProtocolInd::copy(const NetworkProtocolInd& other)
{
    this->networkProtocolHeader = other.networkProtocolHeader;
}

void NetworkProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->networkProtocolHeader);
}

void NetworkProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->networkProtocolHeader);
}

const ChunkPtr& NetworkProtocolInd::getNetworkProtocolHeader() const
{
    return this->networkProtocolHeader;
}

void NetworkProtocolInd::setNetworkProtocolHeader(const ChunkPtr& networkProtocolHeader)
{
    this->networkProtocolHeader = networkProtocolHeader;
}

class NetworkProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_networkProtocolHeader,
    };
  public:
    NetworkProtocolIndDescriptor();
    virtual ~NetworkProtocolIndDescriptor();

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

Register_ClassDescriptor(NetworkProtocolIndDescriptor)

NetworkProtocolIndDescriptor::NetworkProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::NetworkProtocolInd)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

NetworkProtocolIndDescriptor::~NetworkProtocolIndDescriptor()
{
    delete[] propertyNames;
}

bool NetworkProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetworkProtocolInd *>(obj)!=nullptr;
}

const char **NetworkProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NetworkProtocolIndDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NetworkProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int NetworkProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_networkProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *NetworkProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkProtocolHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int NetworkProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "networkProtocolHeader") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *NetworkProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkPtr",    // FIELD_networkProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetworkProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *NetworkProtocolIndDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int NetworkProtocolIndDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NetworkProtocolIndDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NetworkProtocolInd'", field);
    }
}

const char *NetworkProtocolIndDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetworkProtocolIndDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_networkProtocolHeader: return "";
        default: return "";
    }
}

void NetworkProtocolIndDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NetworkProtocolInd'", field);
    }
}

omnetpp::cValue NetworkProtocolIndDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_networkProtocolHeader: return omnetpp::toAnyPtr(&pp->getNetworkProtocolHeader()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NetworkProtocolInd' as cValue -- field index out of range?", field);
    }
}

void NetworkProtocolIndDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NetworkProtocolInd'", field);
    }
}

const char *NetworkProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_networkProtocolHeader: return omnetpp::opp_typename(typeid(ChunkPtr));
        default: return nullptr;
    };
}

omnetpp::any_ptr NetworkProtocolIndDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_networkProtocolHeader: return omnetpp::toAnyPtr(&pp->getNetworkProtocolHeader()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NetworkProtocolIndDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NetworkProtocolInd *pp = omnetpp::fromAnyPtr<NetworkProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NetworkProtocolInd'", field);
    }
}

Register_Class(MacProtocolReq)

MacProtocolReq::MacProtocolReq() : ::inet::ProtocolTagBase()
{
}

MacProtocolReq::MacProtocolReq(const MacProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

MacProtocolReq::~MacProtocolReq()
{
}

MacProtocolReq& MacProtocolReq::operator=(const MacProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void MacProtocolReq::copy(const MacProtocolReq& other)
{
}

void MacProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void MacProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class MacProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    MacProtocolReqDescriptor();
    virtual ~MacProtocolReqDescriptor();

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

Register_ClassDescriptor(MacProtocolReqDescriptor)

MacProtocolReqDescriptor::MacProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MacProtocolReq)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

MacProtocolReqDescriptor::~MacProtocolReqDescriptor()
{
    delete[] propertyNames;
}

bool MacProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacProtocolReq *>(obj)!=nullptr;
}

const char **MacProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacProtocolReqDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int MacProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *MacProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int MacProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *MacProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **MacProtocolReqDescriptor::getFieldPropertyNames(int field) const
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

const char *MacProtocolReqDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MacProtocolReqDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MacProtocolReqDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacProtocolReq'", field);
    }
}

const char *MacProtocolReqDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacProtocolReqDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void MacProtocolReqDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacProtocolReq'", field);
    }
}

omnetpp::cValue MacProtocolReqDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacProtocolReq' as cValue -- field index out of range?", field);
    }
}

void MacProtocolReqDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacProtocolReq'", field);
    }
}

const char *MacProtocolReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr MacProtocolReqDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacProtocolReqDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolReq *pp = omnetpp::fromAnyPtr<MacProtocolReq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacProtocolReq'", field);
    }
}

Register_Class(MacProtocolInd)

MacProtocolInd::MacProtocolInd() : ::inet::ProtocolTagBase()
{
}

MacProtocolInd::MacProtocolInd(const MacProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

MacProtocolInd::~MacProtocolInd()
{
}

MacProtocolInd& MacProtocolInd::operator=(const MacProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void MacProtocolInd::copy(const MacProtocolInd& other)
{
    this->macProtocolHeader = other.macProtocolHeader;
}

void MacProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->macProtocolHeader);
}

void MacProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->macProtocolHeader);
}

const ChunkPtr& MacProtocolInd::getMacProtocolHeader() const
{
    return this->macProtocolHeader;
}

void MacProtocolInd::setMacProtocolHeader(const ChunkPtr& macProtocolHeader)
{
    this->macProtocolHeader = macProtocolHeader;
}

class MacProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_macProtocolHeader,
    };
  public:
    MacProtocolIndDescriptor();
    virtual ~MacProtocolIndDescriptor();

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

Register_ClassDescriptor(MacProtocolIndDescriptor)

MacProtocolIndDescriptor::MacProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MacProtocolInd)), "inet::ProtocolTagBase")
{
    propertyNames = nullptr;
}

MacProtocolIndDescriptor::~MacProtocolIndDescriptor()
{
    delete[] propertyNames;
}

bool MacProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacProtocolInd *>(obj)!=nullptr;
}

const char **MacProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MacProtocolIndDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MacProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MacProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_macProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MacProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "macProtocolHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MacProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "macProtocolHeader") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MacProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkPtr",    // FIELD_macProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MacProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *MacProtocolIndDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MacProtocolIndDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MacProtocolIndDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MacProtocolInd'", field);
    }
}

const char *MacProtocolIndDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacProtocolIndDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_macProtocolHeader: return "";
        default: return "";
    }
}

void MacProtocolIndDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacProtocolInd'", field);
    }
}

omnetpp::cValue MacProtocolIndDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_macProtocolHeader: return omnetpp::toAnyPtr(&pp->getMacProtocolHeader()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MacProtocolInd' as cValue -- field index out of range?", field);
    }
}

void MacProtocolIndDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacProtocolInd'", field);
    }
}

const char *MacProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_macProtocolHeader: return omnetpp::opp_typename(typeid(ChunkPtr));
        default: return nullptr;
    };
}

omnetpp::any_ptr MacProtocolIndDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        case FIELD_macProtocolHeader: return omnetpp::toAnyPtr(&pp->getMacProtocolHeader()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MacProtocolIndDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MacProtocolInd *pp = omnetpp::fromAnyPtr<MacProtocolInd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MacProtocolInd'", field);
    }
}

Register_Class(IsBurstyTag)

IsBurstyTag::IsBurstyTag() : ::inet::TagBase()
{
}

IsBurstyTag::IsBurstyTag(const IsBurstyTag& other) : ::inet::TagBase(other)
{
    copy(other);
}

IsBurstyTag::~IsBurstyTag()
{
}

IsBurstyTag& IsBurstyTag::operator=(const IsBurstyTag& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void IsBurstyTag::copy(const IsBurstyTag& other)
{
    this->is_bursty = other.is_bursty;
}

void IsBurstyTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->is_bursty);
}

void IsBurstyTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->is_bursty);
}

bool IsBurstyTag::getIs_bursty() const
{
    return this->is_bursty;
}

void IsBurstyTag::setIs_bursty(bool is_bursty)
{
    this->is_bursty = is_bursty;
}

class IsBurstyTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_is_bursty,
    };
  public:
    IsBurstyTagDescriptor();
    virtual ~IsBurstyTagDescriptor();

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

Register_ClassDescriptor(IsBurstyTagDescriptor)

IsBurstyTagDescriptor::IsBurstyTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IsBurstyTag)), "inet::TagBase")
{
    propertyNames = nullptr;
}

IsBurstyTagDescriptor::~IsBurstyTagDescriptor()
{
    delete[] propertyNames;
}

bool IsBurstyTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IsBurstyTag *>(obj)!=nullptr;
}

const char **IsBurstyTagDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *IsBurstyTagDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int IsBurstyTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int IsBurstyTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_is_bursty
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *IsBurstyTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "is_bursty",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int IsBurstyTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "is_bursty") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *IsBurstyTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_is_bursty
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **IsBurstyTagDescriptor::getFieldPropertyNames(int field) const
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

const char *IsBurstyTagDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int IsBurstyTagDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void IsBurstyTagDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'IsBurstyTag'", field);
    }
}

const char *IsBurstyTagDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IsBurstyTagDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        case FIELD_is_bursty: return bool2string(pp->getIs_bursty());
        default: return "";
    }
}

void IsBurstyTagDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        case FIELD_is_bursty: pp->setIs_bursty(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IsBurstyTag'", field);
    }
}

omnetpp::cValue IsBurstyTagDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        case FIELD_is_bursty: return pp->getIs_bursty();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'IsBurstyTag' as cValue -- field index out of range?", field);
    }
}

void IsBurstyTagDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        case FIELD_is_bursty: pp->setIs_bursty(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IsBurstyTag'", field);
    }
}

const char *IsBurstyTagDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr IsBurstyTagDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void IsBurstyTagDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    IsBurstyTag *pp = omnetpp::fromAnyPtr<IsBurstyTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'IsBurstyTag'", field);
    }
}

Register_Class(PayloadInfoTag)

PayloadInfoTag::PayloadInfoTag() : ::inet::TagBase()
{
}

PayloadInfoTag::PayloadInfoTag(const PayloadInfoTag& other) : ::inet::TagBase(other)
{
    copy(other);
}

PayloadInfoTag::~PayloadInfoTag()
{
}

PayloadInfoTag& PayloadInfoTag::operator=(const PayloadInfoTag& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void PayloadInfoTag::copy(const PayloadInfoTag& other)
{
    this->payload_length = other.payload_length;
    this->total_length = other.total_length;
    this->offset = other.offset;
}

void PayloadInfoTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->payload_length);
    doParsimPacking(b,this->total_length);
    doParsimPacking(b,this->offset);
}

void PayloadInfoTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->payload_length);
    doParsimUnpacking(b,this->total_length);
    doParsimUnpacking(b,this->offset);
}

b PayloadInfoTag::getPayload_length() const
{
    return this->payload_length;
}

void PayloadInfoTag::setPayload_length(b payload_length)
{
    this->payload_length = payload_length;
}

b PayloadInfoTag::getTotal_length() const
{
    return this->total_length;
}

void PayloadInfoTag::setTotal_length(b total_length)
{
    this->total_length = total_length;
}

b PayloadInfoTag::getOffset() const
{
    return this->offset;
}

void PayloadInfoTag::setOffset(b offset)
{
    this->offset = offset;
}

class PayloadInfoTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_payload_length,
        FIELD_total_length,
        FIELD_offset,
    };
  public:
    PayloadInfoTagDescriptor();
    virtual ~PayloadInfoTagDescriptor();

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

Register_ClassDescriptor(PayloadInfoTagDescriptor)

PayloadInfoTagDescriptor::PayloadInfoTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PayloadInfoTag)), "inet::TagBase")
{
    propertyNames = nullptr;
}

PayloadInfoTagDescriptor::~PayloadInfoTagDescriptor()
{
    delete[] propertyNames;
}

bool PayloadInfoTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PayloadInfoTag *>(obj)!=nullptr;
}

const char **PayloadInfoTagDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PayloadInfoTagDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PayloadInfoTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int PayloadInfoTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_payload_length
        FD_ISEDITABLE,    // FIELD_total_length
        FD_ISEDITABLE,    // FIELD_offset
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *PayloadInfoTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payload_length",
        "total_length",
        "offset",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int PayloadInfoTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "payload_length") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "total_length") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "offset") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *PayloadInfoTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::b",    // FIELD_payload_length
        "inet::b",    // FIELD_total_length
        "inet::b",    // FIELD_offset
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **PayloadInfoTagDescriptor::getFieldPropertyNames(int field) const
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

const char *PayloadInfoTagDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PayloadInfoTagDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PayloadInfoTagDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PayloadInfoTag'", field);
    }
}

const char *PayloadInfoTagDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PayloadInfoTagDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        case FIELD_payload_length: return unit2string(pp->getPayload_length());
        case FIELD_total_length: return unit2string(pp->getTotal_length());
        case FIELD_offset: return unit2string(pp->getOffset());
        default: return "";
    }
}

void PayloadInfoTagDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        case FIELD_payload_length: pp->setPayload_length(b(string2long(value))); break;
        case FIELD_total_length: pp->setTotal_length(b(string2long(value))); break;
        case FIELD_offset: pp->setOffset(b(string2long(value))); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PayloadInfoTag'", field);
    }
}

omnetpp::cValue PayloadInfoTagDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        case FIELD_payload_length: throw omnetpp::cRuntimeError("Cannot return field 'inet::PayloadInfoTag::payload_length' (type 'b') as cValue, please provide @toValue in the msg file");
        case FIELD_total_length: throw omnetpp::cRuntimeError("Cannot return field 'inet::PayloadInfoTag::total_length' (type 'b') as cValue, please provide @toValue in the msg file");
        case FIELD_offset: throw omnetpp::cRuntimeError("Cannot return field 'inet::PayloadInfoTag::offset' (type 'b') as cValue, please provide @toValue in the msg file");
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PayloadInfoTag' as cValue -- field index out of range?", field);
    }
}

void PayloadInfoTagDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        case FIELD_payload_length: throw omnetpp::cRuntimeError("Cannot set field 'inet::PayloadInfoTag::payload_length' (type 'b') from cValue, please provide @fromValue in the msg file");
        case FIELD_total_length: throw omnetpp::cRuntimeError("Cannot set field 'inet::PayloadInfoTag::total_length' (type 'b') from cValue, please provide @fromValue in the msg file");
        case FIELD_offset: throw omnetpp::cRuntimeError("Cannot set field 'inet::PayloadInfoTag::offset' (type 'b') from cValue, please provide @fromValue in the msg file");
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PayloadInfoTag'", field);
    }
}

const char *PayloadInfoTagDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PayloadInfoTagDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PayloadInfoTagDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PayloadInfoTag *pp = omnetpp::fromAnyPtr<PayloadInfoTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PayloadInfoTag'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

