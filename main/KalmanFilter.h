#ifndef KalmanFilter_h
#define KalmanFilter_h

class KalmanFilter
{
public:
  KalmanFilter();
  void Yiorderfilter(float angle_m, float gyro_m,float dt,float K1);
  void Angletest_x(int16_t ax,int16_t az,int16_t gz,int16_t gy);
  void Angletest_y(int16_t ay,int16_t az,int16_t gz,int16_t gx);
  float Gyro_x,Gyro_y,Gyro_z;
  float accelz = 0;
  float angle6; 
  float K1;
  float dt; 
};

KalmanFilter::KalmanFilter(){
   angle6 = 0;
   K1 = 0.05;
   dt = 0.005;
}

void KalmanFilter::Yiorderfilter(float angle_m, float gyro_m,float dt,float K1)  //一阶互补滤波
{
  angle6 = K1 * angle_m + (1 - K1) * (angle6 + gyro_m * dt);
}

void KalmanFilter::Angletest_x(int16_t ax,int16_t az,int16_t gz,int16_t gy)
{
  
  if (gz > 32768) gz -= 65536;              //强制转换2g  1g
  Gyro_z = -gz / 131;                      //Z轴参数转换
  accelz = az / 16.4;
  float angleAx = atan2(ax, az) * 180 / PI; //计算与x轴夹角
  Gyro_y = -gy / 131.00; //计算角速度
  Yiorderfilter(angleAx, Gyro_y, dt, K1); //一阶滤波
}

void KalmanFilter::Angletest_y(int16_t ay,int16_t az,int16_t gz,int16_t gx)
{
  if (gz > 32768) gz -= 65536;              //强制转换2g  1g
  Gyro_z = -gz / 131;                      //Z轴参数转换
  accelz = az / 16.4;
  float angleAx = atan2(ay, az) * 180 / PI; //计算与x轴夹角
  Gyro_x = -gx / 131.00; //计算角速度
  Yiorderfilter(angleAx, Gyro_x, dt, K1); //一阶滤波
}

KalmanFilter KalFilter_x;
KalmanFilter KalFilter_y;
#endif
