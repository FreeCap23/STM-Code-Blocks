/**
 * @file ADXL345_regs.h
 * @brief Register map and definitions for the ADXL345
 *
 * This file defines the register addresses and basic reset values for the ADXL345.
 * Registers are grouped by functionality for clarity. Reserved registers are excluded.
 *
 * @author Dionisie Stratulat
 */

#ifndef ADXL345_REGS_H
#define ADXL345_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @defgroup ADXL345 ADXL345 Accelerometer
 *  @{
 *  @defgroup ADXL345_REGISTERS Register Map
 *  @brief Register addresses for the ADXL345
 *  @{
 *  @defgroup ADXL345_ID_REG Device Identification
 *  @brief Device ID and reserved space
 *  @{
 */
#define ADXL345_REG_DEVID         0x00  /**< Device ID (Read-only), reset: 0xE5 */
/** @} */

/** @defgroup ADXL345_OFFSET_REGS Offset Calibration
 *  @brief Offset calibration for each axis
 *  @{
 */
#define ADXL345_REG_OFSX          0x1E  /**< X-axis offset (R/W) */
#define ADXL345_REG_OFSY          0x1F  /**< Y-axis offset (R/W) */
#define ADXL345_REG_OFSZ          0x20  /**< Z-axis offset (R/W) */
/** @} */

/** @defgroup ADXL345_TAP_REGS Tap Detection Configuration
 *  @brief Registers related to single/double tap detection
 *  @{
 */
#define ADXL345_REG_THRESH_TAP    0x1D  /**< Tap threshold (R/W) */
#define ADXL345_REG_DUR           0x21  /**< Tap duration (R/W) */
#define ADXL345_REG_LATENT        0x22  /**< Tap latency (R/W) */
#define ADXL345_REG_WINDOW        0x23  /**< Tap window (R/W) */
#define ADXL345_REG_TAP_AXES      0x2A  /**< Tap axis control (R/W) */
#define ADXL345_REG_ACT_TAP_STATUS 0x2B /**< Tap status (Read-only) */
/** @} */

/** @defgroup ADXL345_ACTIVITY_REGS Activity/Inactivity Detection
 *  @brief Registers for detecting motion and free-fall
 *  @{
 */
#define ADXL345_REG_THRESH_ACT    0x24  /**< Activity threshold (R/W) */
#define ADXL345_REG_THRESH_INACT  0x25  /**< Inactivity threshold (R/W) */
#define ADXL345_REG_TIME_INACT    0x26  /**< Inactivity time (R/W) */
#define ADXL345_REG_ACT_INACT_CTL 0x27  /**< Axis enable control for activity/inactivity (R/W) */
#define ADXL345_REG_THRESH_FF     0x28  /**< Free-fall threshold (R/W) */
#define ADXL345_REG_TIME_FF       0x29  /**< Free-fall time (R/W) */
/** @} */

/** @defgroup ADXL345_POWER_REGS Power and Data Rate
 *  @brief Power control and data rate settings
 *  @{
 */
#define ADXL345_REG_BW_RATE       0x2C  /**< Data rate and power mode (R/W), reset: 0x0A */
#define ADXL345_REG_POWER_CTL     0x2D  /**< Power control (R/W) */
#define ADXL345_REG_DATA_FORMAT   0x31  /**< Data format control (R/W) */
/** @} */

/** @defgroup ADXL345_INT_REGS Interrupt Control and Status
 *  @brief Interrupt enable, map, and source
 *  @{
 */
#define ADXL345_REG_INT_ENABLE    0x2E  /**< Interrupt enable (R/W) */
#define ADXL345_REG_INT_MAP       0x2F  /**< Interrupt mapping (R/W) */
#define ADXL345_REG_INT_SOURCE    0x30  /**< Interrupt source (Read-only) */
/** @} */

/** @defgroup ADXL345_OUTPUT_REGS Output Data Registers
 *  @brief ADXL345eration output data per axis (Read-only)
 *  @{
 */
#define ADXL345_REG_DATAX0        0x32  /**< X-axis data low byte */
#define ADXL345_REG_DATAX1        0x33  /**< X-axis data high byte */
#define ADXL345_REG_DATAY0        0x34  /**< Y-axis data low byte */
#define ADXL345_REG_DATAY1        0x35  /**< Y-axis data high byte */
#define ADXL345_REG_DATAZ0        0x36  /**< Z-axis data low byte */
#define ADXL345_REG_DATAZ1        0x37  /**< Z-axis data high byte */
/** @} */

/** @defgroup ADXL345_FIFO_REGS FIFO Control and Status
 *  @brief FIFO configuration and monitoring
 *  @{
 */
#define ADXL345_REG_FIFO_CTL      0x38  /**< FIFO control (R/W) */
#define ADXL345_REG_FIFO_STATUS   0x39  /**< FIFO status (Read-only) */
/** @} */

/** @} */ // End of ADXL345_REGISTERS

/** @} */ // End of ADXL345
#ifdef __cplusplus
}
#endif

#endif // ADXL345_REGS_H
