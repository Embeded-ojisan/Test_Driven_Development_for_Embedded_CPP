#ifndef D_P3BuildTime_H
#define D_P3BuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  P3BuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class P3BuildTime
  {
  public:
    explicit P3BuildTime();
    virtual ~P3BuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    P3BuildTime(const P3BuildTime&);
    P3BuildTime& operator=(const P3BuildTime&);

  };

#endif  // D_P3BuildTime_H
