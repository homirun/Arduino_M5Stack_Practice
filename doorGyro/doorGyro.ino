#include <M5Stack.h>
#include "utility/MPU9250.h"

MPU9250 IMU;

void setup(){
    M5.begin();
    Wire.begin();
    M5.Lcd.setTextSize(2);

    // センサーの誤差修正？と初期化
    IMU.calibrateMPU9250(IMU.gyroBias, IMU.accelBias);
    IMU.initMPU9250();
}

void loop(){
    if(IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01){
        M5.Lcd.clear();
        IMU.readAccelData(IMU.accelCount);
        IMU.getAres();
        M5.Lcd.printf("X Acceleration: %5d [mg]\n",(int)((float)IMU.accelCount[0] * IMU.aRes * 1000));
        M5.Lcd.printf("Y Acceleration: %5d [mg]\n",(int)((float)IMU.accelCount[1] * IMU.aRes * 1000));
        M5.Lcd.printf("Z Acceleration: %5d [mg]\n",(int)((float)IMU.accelCount[2] * IMU.aRes * 1000));

        IMU.readGyroData(IMU.gyroCount);
        IMU.getGres();
        int ZAccel = (int)((float)IMU.accelCount[0] * IMU.aRes * 1000);
        if (ZAccel < -50){
            M5.Lcd.clear();
            M5.Lcd.printf("%s", "Open");
            M5.Lcd.printf("X Accel: %6d [deg/s]\n", ZAccel);

        }
        delay(100);
        M5.Lcd.setCursor(0,0);

    }
}