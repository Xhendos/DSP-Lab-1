# DSP-Lab-1



## Microcontroller Development Board 

## IMU Development Board 
<img src="fig/imu_sensor_dev_board.png" alt="IMU Sensor development board" width="35%" />

I am using a board which is not really an integrated IMU sensor in 1 sillicon package, but instead a board which has 2 sensors assembled on it. The first sensor being the LSM303DLHC which is an accelerometer and magnetometer in one. The second sensor being the L3GD20 which is a gyroscope. You can find the AliExpress link [here](https://nl.aliexpress.com/item/32903832768.html?spm=a2g0o.productlist.main.9.3843115bjwHG4B&algo_pvid=7ba10ca8-d109-47c9-9cd3-4fb200163a69&algo_exp_id=7ba10ca8-d109-47c9-9cd3-4fb200163a69-4&pdp_npi=4%40dis%21EUR%215.59%215.59%21%21%215.94%215.94%21%402103835e17306675901261026ede18%2165798327221%21sea%21NL%21822730915%21X&curPageLogUid=4SDKWKGLpj4c&utparam-url=scene%3Asearch%7Cquery_from%3A). It uses i2c as a communication protocol. 

## Pressure Sensor Development Board
<img src="fig/pressure_sensor_dev_board.png" alt="Pressure Sensor development board" width="35%" />

I am using the BMP280 digital pressure sensor developed by Bosch. This one can be widely ordered on AliExpress by various sellers. I have chosen to buy [this](https://nl.aliexpress.com/item/1005006733065626.html?spm=a2g0o.productlist.main.11.1945b4Ryb4Ryvj&algo_pvid=1eaab135-3305-4090-9e63-5ac73ac4ea28&algo_exp_id=1eaab135-3305-4090-9e63-5ac73ac4ea28-5&pdp_npi=4%40dis%21EUR%214.68%214.49%21%21%214.97%214.77%21%402103854017306672518593639ee944%2112000038122257904%21sea%21NL%21822730915%21X&curPageLogUid=bLYCUn4kQhUP&utparam-url=scene%3Asearch%7Cquery_from%3A) board because it also ships with the AHT20 temperature and humidity sensor which may come in handy in the future. The BMP280 development board only allows us to use i2c although the sensor supports spi as well.
