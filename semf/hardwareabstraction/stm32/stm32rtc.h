/**
 * @file stm32rtc.h
 * @date 21.12.2019
 * @author fs
 * @copyright Copyright (C) querdenker engineering GmbH - All Rights Reserved
 *            For detailed information, read the license file in
 *            the project root directory.
 */

#ifndef SEMF_HARDWAREABSTRACTION_STM32_STM32RTC_H_
#define SEMF_HARDWAREABSTRACTION_STM32_STM32RTC_H_

#include <semf/hardwareabstraction/stm32/stm32.h>

#if defined(STM32) && defined(HAL_RTC_MODULE_ENABLED)
#include <semf/system/rtc.h>
namespace semf
{
/**
 * @brief \c Rtc implementation for STM32.
 */
class Stm32Rtc : public Rtc
{
public:
	/**Error codes for this class. Error ID identify a unique error() / onError call (excluding transferring).*/
	enum class ErrorCode : uint8_t
	{
		SetMillisecond_HalError = 0,
		SetMillisecond_HalBusy,
		SetMillisecond_HalTimeout,
		SetSecond_HalError,
		SetSecond_HalBusy,
		SetSecond_HalTimeout,
		SetMinute_HalError,
		SetMinute_HalBusy,
		SetMinute_HalTimeout,
		SetHour_HalError,
		SetHour_HalBusy,
		SetHour_HalTimeout,
		SetDay_HalError,
		SetDay_HalBusy,
		SetDay_HalTimeout,
		SetMonth_HalError,
		SetMonth_HalBusy,
		SetMonth_HalTimeout,
		SetYear_HalError,
		SetYear_HalBusy,
		SetYear_HalTimeout,
		HalTime_HalError,
		HalTime_HalBusy,
		HalTime_HalTimeout,
		HalDate_HalError,
		HalDate_HalBusy,
		HalDate_HalTimeout
	};

	/**
	 * @brief Constructor.
	 * @param hrtc Hardware handle.
	 */
	explicit Stm32Rtc(RTC_HandleTypeDef& hrtc);
	explicit Stm32Rtc(const Stm32Rtc& other) = delete;
	virtual ~Stm32Rtc() = default;

	uint16_t millisecond() const override;
	/**
	 * @copydoc Rtc::setMillisecond()
	 * @throws SetMillisecond_HalError If the ST-HAL returns a hal error.
	 * @throws SetMillisecond_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetMillisecond_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setMillisecond(uint16_t millisecond) override;
	uint8_t second() const override;
	/**
	 * @copydoc Rtc::setSecond()
	 * @throws SetSecond_HalError If the ST-HAL returns a hal error.
	 * @throws SetSecond_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetSecond_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setSecond(uint8_t second) override;
	uint8_t minute() const override;
	/**
	 * @copydoc Rtc::setMinute()
	 * @throws SetMinute_HalError If the ST-HAL returns a hal error.
	 * @throws SetMinute_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetMinute_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setMinute(uint8_t minute) override;
	uint8_t hour() const override;
	/**
	 * @copydoc Rtc::setHour()
	 * @throws SetHour_HalError If the ST-HAL returns a hal error.
	 * @throws SetHour_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetHour_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setHour(uint8_t hour) override;
	uint8_t day() const override;
	/**
	 * @copydoc Rtc::setDay()
	 * @throws SetDay_HalError If the ST-HAL returns a hal error.
	 * @throws SetDay_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetDay_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setDay(uint8_t day) override;
	uint8_t month() const override;
	/**
	 * @copydoc Rtc::setMonth()
	 * @throws SetDay_HalError If the ST-HAL returns a hal error.
	 * @throws SetDay_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetDay_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setMonth(uint8_t month) override;
	uint16_t year() const override;
	/**
	 * @copydoc Rtc::setYear()
	 * @throws SetYear_HalError If the ST-HAL returns a hal error.
	 * @throws SetYear_HalBusy If the ST-HAL returns a hal busy.
	 * @throws SetYear_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	void setYear(uint16_t year) override;

private:
	/**handle for the stm32 hal library*/
	RTC_HandleTypeDef* m_hrtc;
	/**
	 * @brief Retrieves the currect time from the rtc.
	 * @return Current time in native format.
	 * @throws HalTime_HalError If the ST-HAL returns a hal error.
	 * @throws HalTime_HalBusy If the ST-HAL returns a hal busy.
	 * @throws HalTime_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	RTC_TimeTypeDef halTime() const;
	/**
	 * @brief Retrieves the currect date from the rtc.
	 * @return Current date in native format.
	 * @throws HalDate_HalError If the ST-HAL returns a hal error.
	 * @throws HalDate_HalBusy If the ST-HAL returns a hal busy.
	 * @throws HalDate_HalTimeout If the ST-HAL returns a hal timeout.
	 */
	RTC_DateTypeDef halDate() const;
	/**Class ID for error tracing.*/
	static constexpr Error::ClassID kSemfClassId = Error::ClassID::Stm32Rtc;
};
} /* namespace semf */
#endif
#endif /* SEMF_HARDWAREABSTRACTION_STM32_STM32RTC_H_ */
