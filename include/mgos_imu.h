/*
 * Copyright 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "mgos.h"
#include "mgos_i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

enum mgos_imu_acc_type {
  ACC_NONE = 0,
  ACC_MPU9250
};

enum mgos_imu_gyro_type {
  GYRO_NONE = 0,
  GYRO_MPU9250
};

enum mgos_imu_mag_type {
  MAG_NONE = 0,
  MAG_AK8963
};

struct mgos_imu;

struct mgos_imu *mgos_imu_create_i2c(struct mgos_i2c *i2c);
bool mgos_imu_add_gyroscope_i2c(struct mgos_imu *sensor, uint8_t i2caddr, enum mgos_imu_gyro_type type);
bool mgos_imu_add_accelerometer_i2c(struct mgos_imu *sensor, uint8_t i2caddr, enum mgos_imu_acc_type type);
bool mgos_imu_add_magnetometer_i2c(struct mgos_imu *sensor, uint8_t i2caddr, enum mgos_imu_mag_type type);

void mgos_imu_destroy(struct mgos_imu **sensor);

bool mgos_imu_has_accelerometer(struct mgos_imu *sensor);
bool mgos_imu_has_gyroscope(struct mgos_imu *sensor);
bool mgos_imu_has_magnetometer(struct mgos_imu *sensor);

/* Read all available sensor data from the IMU */
bool mgos_imu_read(struct mgos_imu *sensor);

/* Return accelerometer data in units of m/s/s */
bool mgos_imu_get_accelerometer(struct mgos_imu *sensor, float *x, float *y, float *z);

/* Return accelerometer data in units of deg/sec rotation rate */
bool mgos_imu_get_gyroscope(struct mgos_imu *sensor, float *x, float *y, float *z);

/* Return magnetometer data in units of microtesla (1 microtesla = 10 milligauss) */
bool mgos_imu_get_magnetometer(struct mgos_imu *sensor, float *x, float *y, float *z);

/* Return compass heading based on magnetometer data, from [0..359] */
bool mgos_imu_get_compass_heading(struct mgos_imu *sensor, uint16_t *heading);

/*
 * Initialization function for MGOS -- currently a noop.
 */
bool mgos_imu_init(void);

#ifdef __cplusplus
}
#endif