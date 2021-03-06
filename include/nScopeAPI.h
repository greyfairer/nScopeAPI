/*******************************************************
 nScopeAPI - Multi-Platform library for
 communication with nScope devices.

 David Meyer

 10/23/2014

 Copyright 2014, All Rights Reserved.

********************************************************/

/** @file nScopeAPI.h

    @brief Main header file that includes the entire API
 */

#ifndef NSCOPEAPI_H__
#define NSCOPEAPI_H__


#include "nScopeAPI_defs.h"
#include "nScopeAPI_requests.h"
#include "nScopeAPI_analogInputs.h"
#include "nScopeAPI_sampleTiming.h"
#include "nScopeAPI_trigger.h"
#include "nScopeAPI_analogOutputs.h"
#include "nScopeAPI_pulseGenerators.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif



	/** @brief Open a connected nScope device and initialize it.

        Looks for a nScope device, connects to it, then runs nScope_initialize()
		Stores the resulting #ScopeHandle object in *nScope_p

		@returns
			#ErrorType
        @param [in] powerOn
            true turns nScope on when first opened, false leaves nScope in
            its current state
        @param [out] nScope_p
            a pointer to a #ScopeHandle object
	*/
	NSCOPE_API ErrorType nScope_open(bool powerOn, ScopeHandle* nScope_p);

    /** @brief Close and clean a connected nScope device.

        @returns
            #ErrorType
        @param [in] nScope_p
            pointer to a #ScopeHandle object
    */
	NSCOPE_API ErrorType nScope_close(ScopeHandle* nScope_p);

    /** @brief Clean up an nScope device.

        This function cleans the memory that was used for an nScope object. This function
        is called by nScope_close(), so it is only needed when nScope is disconnected for an
        unknown reason.

        @returns
            #ErrorType
        @param [in] nScope_p
            pointer to a #ScopeHandle object
    */
    NSCOPE_API ErrorType nScope_clean(ScopeHandle* nScope_p);

    /** @brief Initialize an nScope with the default configuration.

        This function is called by nScope_open(), so it's only needed to reset
        the configuration if it ever reaches an unknown state.

        The default configuration is:

        @returns
            #ErrorType
        @param [in] nScope
            nScope handle
    */
	NSCOPE_API ErrorType nScope_initialize(ScopeHandle nScope);

    /** @brief Read how much power is being used by nScope

        @returns
            #ErrorType
        @param [in] nScope
            nScope handle
        @param [out] powerUsage
            pointer to a variable to store the amount of power being
            used by nScope in watts
    */
    NSCOPE_API ErrorType nScope_get_power_usage(ScopeHandle nScope, double *powerUsage);

    /** @brief Read the #PowerState of the nScope

        @returns
            #ErrorType
        @param [in] nScope
            nScope handle
        @param [out] powerState
            pointer to a variable to store nScope's current power state
    */
    NSCOPE_API ErrorType nScope_get_power_state(ScopeHandle nScope, PowerState* powerState);

    /** @brief find the firmware loader

        @returns
            #ErrorType
    */
    NSCOPE_API ErrorType nScope_find_firmware_loader();

    /** @brief write the firmware to the loader

        @returns
            #ErrorType
    */
    NSCOPE_API ErrorType nScope_write_to_loader();

    /** @brief load the nScope with current firmware

        calls both nScope_find_firmware_loader() and nScope_write_to_loader()

        @returns
            #ErrorType
    */
    NSCOPE_API ErrorType nScope_load_firmware();

    /** @brief check the version of this API

        @returns
            #ErrorType
        @param [out] apiVersion
            pointer to a variable to store the current API version
    */
    NSCOPE_API ErrorType nScope_check_API_version(double* apiVersion);

    /** @brief check the version of the connected firmware

        @returns
            #ErrorType
        @param [out] fwVersion
            pointer to a variable to store the current firmware version
    */
    NSCOPE_API ErrorType nScope_check_FW_version(double* fwVersion);

	/** @brief check the build number of this API

		@returns
			#ErrorType
		@param [out] apiVersion
			pointer to a variable to store the current API build
	*/
	NSCOPE_API ErrorType nScope_check_API_build(int* buildNo);

#ifdef __cplusplus
}
#endif

#endif
