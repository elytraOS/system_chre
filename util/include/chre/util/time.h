/*
 * Copyright (C) 2016 The Android Open Source Project
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

#ifndef CHRE_UTIL_TIME_H_
#define CHRE_UTIL_TIME_H_

#include <cstdint>

namespace chre {

class Seconds {
 public:
  /**
   * Construct a Seconds time duration given a value.
   */
  constexpr explicit Seconds(uint64_t seconds);

  /**
   * Converts the underlying seconds to a raw uint64_t representation of
   * nanoseconds. Handles overflyw by returning UINT64_MAX.
   *
   * @return the value of seconds converted to nanoseconds
   */
  constexpr uint64_t toRawNanoseconds() const;

 private:
  uint64_t mSeconds;
};

/**
 * Represents a duration of time in milliseconds.
 */
class Milliseconds {
 public:
  /**
   * Construct a Milliseconds time duration given a value.
   */
  constexpr explicit Milliseconds(uint64_t milliseconds);

  /**
   * Converts the underlying milliseconds to a raw uint64_t representation of
   * nanoseconds. Handles overflow by returning UINT64_MAX.
   *
   * @return the value of milliseconds converted to nanoseconds
   */
  constexpr uint64_t toRawNanoseconds() const;

 private:
  //! Store the time duration.
  uint64_t mMilliseconds;
};

/**
 * Represents a duration of time in nanoseconds.
 */
class Nanoseconds {
 public:
  /**
   * Default constructs a Nanoseconds time duration to zero.
   */
  constexpr Nanoseconds();

  /**
   * Constructs a Nanoseconds time duration given a value.
   */
  constexpr explicit Nanoseconds(uint64_t nanoseconds);

  /**
   * Converts a milliseconds value to nanoseconds.
   */
  constexpr Nanoseconds(Milliseconds milliseconds);

  /**
   * Converts the underlying nanoseconds to a raw uint64_t representation of
   * nanoseconds.
   *
   * @return the value of nanoseconds
   */
  constexpr uint64_t toRawNanoseconds() const;

 private:
  uint64_t mNanoseconds;
};

/**
 * Add seconds to nanoseconds.
 *
 * @param seconds the seconds duration
 * @param nanoseconds the nanoseconds duration
 * @return the added time quantity expressed in nanoseconds
 */
constexpr Nanoseconds operator+(const Seconds& seconds,
                                const Nanoseconds& nanoseconds);

/**
 * Add nanoseconds to nanoseconds.
 *
 * @param nanos_a The first nanoseconds duration
 * @param nanos_b The second nanoseconds duration
 * @return The added time quantity expressed in nanoseconds
 */
constexpr Nanoseconds operator+(const Nanoseconds& nanos_a,
                                const Nanoseconds& nanos_b);

/**
 * Subtract two nanosecond durations.
 *
 * @param nanos_a the first nanoseconds duration
 * @param nanos_b the second nanoseconds duration
 * @return the difference between the two durations
 */
constexpr Nanoseconds operator-(const Nanoseconds& nanos_a,
                                const Nanoseconds& nanos_b);

/**
 * Performs a greater than or equal to comparison on two nanoseconds values.
 *
 * @param nanos_a the first nanoseconds duration
 * @param nanos_b the second nanoseconds duration
 * @return Whether nanos_a is greater than or equal to nanos_b.
 */
constexpr bool operator>=(const Nanoseconds& nanos_a,
                          const Nanoseconds& nanos_b);

/**
 * Performs a less than comparison on two nanoseconds values.
 *
 * @param nanos_a the first nanoseconds duration
 * @param nanos_b the second nanoseconds duration
 * @return Whether nanos_a is less than nanos_b.
 */
constexpr bool operator<(const Nanoseconds& nanos_a,
                         const Nanoseconds& nanos_b);

/**
 * Performs a greater than comparison on two nanoseconds values.
 *
 * @param nanos_a the first nanoseconds duration
 * @param nanos_b the second nanoseconds duration
 * @return Whether nanos_a is less than nanos_b.
 */
constexpr bool operator>(const Nanoseconds& nanos_a,
                         const Nanoseconds& nanos_b);

}  // namespace chre

#include "time_impl.h"

#endif // CHRE_UTIL_TIME_H_
