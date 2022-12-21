#ifndef D_2nd_partBuildTime_H
#define D_2nd_partBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  2nd_partBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class 2nd_partBuildTime
  {
  public:
    explicit 2nd_partBuildTime();
    virtual ~2nd_partBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    2nd_partBuildTime(const 2nd_partBuildTime&);
    2nd_partBuildTime& operator=(const 2nd_partBuildTime&);

  };

#endif  // D_2nd_partBuildTime_H
