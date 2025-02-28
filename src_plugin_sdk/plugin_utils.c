/*****************************************************************************
 *   Ledger Plugin SDK
 *   (c) 2023 Ledger SAS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *****************************************************************************/

#include "plugin_utils.h"

bool find_selector(uint32_t selector, const uint32_t *array, size_t size, size_t *idx) {
    for (size_t i = 0; i < size; ++i) {
        if (selector == array[i]) {
            if (idx != NULL) *idx = i;
            return true;
        }
    }
    return false;
}
