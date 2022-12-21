#ifndef D_P2BuildTime_H
#define D_P2BuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  P2BuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class P2BuildTime
  {
  public:
    explicit P2BuildTime();
    virtual ~P2BuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    P2BuildTime(const P2BuildTime&);
    P2BuildTime& operator=(const P2BuildTime&);

  };

#endif  // D_P2BuildTime_H
