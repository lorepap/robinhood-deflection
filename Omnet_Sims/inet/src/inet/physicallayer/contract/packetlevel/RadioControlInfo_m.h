//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/physicallayer/contract/packetlevel/RadioControlInfo.msg.
//

#ifndef __INET__PHYSICALLAYER_RADIOCONTROLINFO_M_H
#define __INET__PHYSICALLAYER_RADIOCONTROLINFO_M_H

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
namespace physicallayer {

class ConfigureRadioCommand;

}  // namespace physicallayer
}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/physicallayer/contract/packetlevel/IModulation_m.h" // import inet.physicallayer.contract.packetlevel.IModulation


namespace inet {
namespace physicallayer {

/**
 * Enum generated from <tt>inet/physicallayer/contract/packetlevel/RadioControlInfo.msg:28</tt> by opp_msgtool.
 * <pre>
 * //
 * // Message kinds for sending commands to the radio.
 * //
 * enum RadioCommandCode
 * {
 *     RADIO_C_CONFIGURE = 1;
 * }
 * </pre>
 */
enum RadioCommandCode {
    RADIO_C_CONFIGURE = 1
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RadioCommandCode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RadioCommandCode& e) { int n; b->unpack(n); e = static_cast<RadioCommandCode>(n); }

/**
 * Class generated from <tt>inet/physicallayer/contract/packetlevel/RadioControlInfo.msg:36</tt> by opp_msgtool.
 * <pre>
 * //
 * // Control info attached to a configure command that is sent to the ~Radio.
 * //
 * class ConfigureRadioCommand extends cObject
 * {
 *     int radioMode = -1;                  // new radio mode or -1 if not set.
 *     W power = W(NaN);                    // new default transmission power in the range (0, +infinity) or NaN if not set.
 *     bps bitrate = bps(NaN);              // new default bitrate in the range (0, +infinity) or NaN if not set.
 *     IModulation *modulation = nullptr;   // new default modulation or nullptr if not set.
 *     Hz centerFrequency = Hz(NaN);       // new default carrier frequency in the range (0, +infinity) or NaN if not set.
 *     Hz bandwidth = Hz(NaN);              // new default bandwidth in the rage (0, +infinity) or NaN if not set.
 * }
 * </pre>
 */
class INET_API ConfigureRadioCommand : public ::omnetpp::cObject
{
  protected:
    int radioMode = -1;
    ::inet::W power = W(NaN);
    ::inet::bps bitrate = bps(NaN);
    IModulation * modulation = nullptr;
    ::inet::Hz centerFrequency = Hz(NaN);
    ::inet::Hz bandwidth = Hz(NaN);

  private:
    void copy(const ConfigureRadioCommand& other);

  protected:
    bool operator==(const ConfigureRadioCommand&) = delete;

  public:
    ConfigureRadioCommand();
    ConfigureRadioCommand(const ConfigureRadioCommand& other);
    virtual ~ConfigureRadioCommand();
    ConfigureRadioCommand& operator=(const ConfigureRadioCommand& other);
    virtual ConfigureRadioCommand *dup() const override {return new ConfigureRadioCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getRadioMode() const;
    virtual void setRadioMode(int radioMode);

    virtual ::inet::W getPower() const;
    virtual void setPower(::inet::W power);

    virtual ::inet::bps getBitrate() const;
    virtual void setBitrate(::inet::bps bitrate);

    virtual const IModulation * getModulation() const;
    virtual IModulation * getModulationForUpdate() { return const_cast<IModulation *>(const_cast<ConfigureRadioCommand*>(this)->getModulation());}
    virtual void setModulation(IModulation * modulation);

    virtual ::inet::Hz getCenterFrequency() const;
    virtual void setCenterFrequency(::inet::Hz centerFrequency);

    virtual ::inet::Hz getBandwidth() const;
    virtual void setBandwidth(::inet::Hz bandwidth);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ConfigureRadioCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ConfigureRadioCommand& obj) {obj.parsimUnpack(b);}


}  // namespace physicallayer
}  // namespace inet


namespace omnetpp {

template<> inline inet::physicallayer::ConfigureRadioCommand *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::physicallayer::ConfigureRadioCommand*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET__PHYSICALLAYER_RADIOCONTROLINFO_M_H

