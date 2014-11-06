/*
 * AliEMCALConfigurationObject.h
 *
 *  Created on: 06.11.2014
 *      Author: markusfasel
 */

#ifndef PWG_EMCAL_ALIEMCALCONFIGURATIONOBJECT_H_
#define PWG_EMCAL_ALIEMCALCONFIGURATIONOBJECT_H_

#include <TNamed.h>

class AliEMCALConfigurationValue {
public:
  AliEMCALConfigurationValue() {}
  virtual ~AliEMCALConfigurationValue() {}

  virtual const char *ToString() const = 0;
};

class AliEMCALConfigurationValueInt : public AliEMCALConfigurationValue{
public:
  AliEMCALConfigurationValueInt(Int_t val):
    AliEMCALConfigurationValue(),
    fValue(val)
  {}
  virtual ~AliEMCALConfigurationValueInt() {}

  void SetValue(Int_t value) { fValue = value; }
  Int_t GetValue() const { return fValue; }

  virtual const char *ToString() const ;
private:
  Int_t fValue;
};

class AliEMCALConfigurationValueFloat : public AliEMCALConfigurationValue{
  AliEMCALConfigurationValueFloat(Float_t val):
    AliEMCALConfigurationValue(),
    fValue(val)
  {}
  virtual ~AliEMCALConfigurationValueFloat() {}

  void SetValue(Float_t value) { fValue = value; }
  Float_t GetValue() const { return fValue; }

  virtual const char *ToString() const;
private:
  Float_t fValue;
};

class AliEMCALConfigurationValueDouble : public AliEMCALConfigurationValue{
  AliEMCALConfigurationValueDouble(Double_t val):
    AliEMCALConfigurationValue(),
    fValue(val)
  {}
  virtual ~AliEMCALConfigurationValueDouble() {}

  void SetValue(Double_t value) { fValue = value; }
  Double_t GetValue() const { return fValue; }

  virtual const char *ToString() const;
private:
  Double_t fValue;
};

class AliEMCALConfigurationValueBool : public AliEMCALConfigurationValue{
  AliEMCALConfigurationValueBool(Bool_t val):
    AliEMCALConfigurationValue(),
    fValue(val)
  {}
  virtual ~AliEMCALConfigurationValueBool() {}

  void SetValue(Bool_t value) { fValue = value; }
  Bool_t GetValue() const { return fValue; }

  virtual const char *ToString() const { return fValue ? "true" : "false"; }
private:
  Bool_t fValue;
};

class AliEMCALConfigurationValueString : public AliEMCALConfigurationValue{
  AliEMCALConfigurationValueString(const char *val):
    AliEMCALConfigurationValue(),
    fValue(val)
  {}
  virtual ~AliEMCALConfigurationValueString() {}

  void SetValue(const char * value) { fValue = value; }
  const char * GetValue() const { return fValue; }

  virtual const char *ToString() const { return fValue; }
private:
  TString fValue;
};

class AliEMCALConfigurationObject : public TNamed {
public:
  AliEMCALConfigurationObject(const char *name, AliEMCALConfigurationValue *value):
    TNamed(name),
    fValue(value)
  {}
  AliEMCALConfigurationObject(const char *key, const char *value);

  virtual ~AliEMCALConfigurationObject(){
    delete fValue;
  }

  void SetValue(AliEMCALConfigurationValue *val){
    if(fValue) delete fValue;
    fValue = val;
  }

  AliEMCALConfigurationValue *GetValue() const { return fValue; }
  const char *ToString() const;

protected:
  AliEMCALConfigurationObject *fValue;
};

#endif /* PWG_EMCAL_ALIEMCALCONFIGURATIONOBJECT_H_ */
