/* Copyright 2020, RespiraWorks

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

 module contributors: verityRF
 The purpose of this module is to recreate fake versions of Arduino routines so
that unit tests of the controller modules can be done on a x86 host. This module
should never end up on an actual Arduino target.
*/

#ifndef ARDUINOSIM_H
#define ARDUINOSIM_H

/*
 * @brief fake Arduino delay routine. Doesn't do anything.
 */
void delay(unsigned long count);

/*
 * @brief fake Arduino analogRead routine. Takes a voltage signal in memory and
 * outputs the corresponding digital representation.
 *
 * @usage Use createStaticAnalogSignal() or createDynamicAnalogSignal()
 * beforehand to setup the voltage signal in memory. Otherwise it'll just return
 * 0's.
 *
 * @param the analog pin to read from. Must be [0, 2].
 *
 * @return The ADC count representing whatever analog signal memory is attached
 * to the specified pin. 10 Bit representation.
 */
int analogRead(int pin);

/*
 * @brief Populates the internal analog signal memory with a fixed value to
 * represent a steady state measurement. Subsequent calls to analogRead for the
 * specified pin will result in the digital representation of this signal.
 *
 * @param pin the analog pin the signal will be sent to. Must be [0, 2].
 *
 * @param val the voltage at the pin. Must be [0, ADC_VREFP]. In Volts.
 */
void createStaticAnalogSignal(int pin, float val);

/*
 * @brief Populates the internal analog signal memory with a dynamic signal to
 * represent a dynamic measurement. Subsequent calls to analogRead for the
 * specified pin will result in the digital representation of this signal.
 *
 * @param pin the analog pin the signal will be sent to. Must be [0, 2].
 *
 * @param buffer Array containing the dynamic voltages at the pin. Each value in
 * the buffer will be constrained to [0, ADC_VREFP]. In Volts.
 */
void createDynamicAnalogSignal(int pin, float *buffer, int count);

/*
 * @brief Resets the internal analog signal memory indexes to 0 for all
 * channels. Useful if you are running repeated tests but need the memory to
 * start from 0 between runs.
 */
void resetAnalogMemoryIndexes();

/*
 * @brief Gets the maximum analog signal memory length, useful for use with
 * createDynamicAnalogSignal()
 *
 * @return Maximum length of an analog signal memory channel
 */
int getSignalChannelDepth();

#endif // ARDUINOSIM_H
