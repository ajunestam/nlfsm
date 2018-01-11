/*
 *
 *    Copyright (c) 2012-2013-2017 Nest Labs, Inc. All Rights Reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 *
 */

/*
 *
 *    Copyright (c) 2008-2013 Nuovation System Designs, LLC
 *    All rights reserved.
 *
 *    IMPORTANT: This software is supplied to you by Nuovation System
 *    Designs, LLC ("Nuovations"). in consideration of your agreement
 *    to the following terms, and your use, installation, modification
 *    or redistribution of this Nuovations software constitutes
 *    acceptance of these terms. If you do not agree with these terms,
 *    please do not use, install, modify or redistribute this
 *    Nuovations software.
 *
 *    In consideration of your agreement to abide by the following
 *    terms, and subject to these terms, Nuovations grants you a
 *    worldwide, non-exclusive license, under Nuovations' copyrights in
 *    this original Nuovations software (the "Nuovations Software"), to
 *    use, reproduce, modify and redistribute the Nuovations Software,
 *    with or without modifications, in source and/or binary forms;
 *    provided that if you redistribute the Nuovations Software in its
 *    entirety and without modifications, you must retain this notice
 *    and the following text and disclaimers in all such
 *    redistributions of the Nuovations Software. Neither the name,
 *    trademarks, service marks or logos of Nuovations may be used to
 *    endorse or promote products derived from the Nuovations Software
 *    without specific prior written permission from Nuovations. Except
 *    as expressly stated in this notice, no other rights or licenses,
 *    express or implied, are granted by Nuovations herein, including
 *    but not limited to any patent rights that may be infringed by
 *    your derivative works or by other works in which the Nuovations
 *    Software may be incorporated.
 *
 *    The Nuovations Software is provided by Nuovations on an "AS IS"
 *    basis. NUOVATIONS MAKES NO WARRANTIES, EXPRESS OR IMPLIED,
 *    INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF
 *    NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *    PURPOSE, REGARDING THE NUOVATIONS SOFTWARE OR ITS USE AND
 *    OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 *
 *    IN NO EVENT SHALL NUOVATIONS BE LIABLE FOR ANY SPECIAL, INDIRECT,
 *    INCIDENTAL OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *    TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ARISING IN ANY WAY
 *    OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION OF
 *    THE NUOVATIONS SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY
 *    OF CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR
 *    OTHERWISE, EVEN IF NUOVATIONS HAS BEEN ADVISED OF THE POSSIBILITY
 *    OF SUCH DAMAGE.
 *
 */

/**
 *    @file
 *      This file defines a class for managing a finite state machine
 *      (FSM) which is effectively a collection of current state,
 *      event and next state transition tuples and a current, starting
 *      state.
 *
 */

#ifndef NLFSM_MACHINE_HPP
#define NLFSM_MACHINE_HPP

#include <stddef.h>

#include <nestlabs/fsm/nlfsm-transition.hpp>

namespace nl {

    namespace Fsm {

        /**
         *
         *  @class Machine
         *
         *  @brief
         *    This class defines an object for managing a finite state
         *    machine (FSM), including its starting state; current
         *    state; and state transition table consisting of tuples
         *    of current state, excitation input event, and next
         *    state.
         *
         */
        class Machine
        {
        public:
            // Con/destructor(s)
            Machine(void);
            Machine(const Transition inTransitions[],
                    size_t inCount,
                    const State &inCurrentState);
            void SetTransitions(const Transition inTransitions[],
                                size_t inCount,
                                const State &inCurrentState);

            const State & GetCurrentState(void) const;
            void SetCurrentState(const State & inState);
            const Transition * FindTransition(const State &inState,
                                              const Event &inEvent) const;

        private:
            State                      mCurrentState;     //!< The current
                                                          //!< state of the
                                                          //!< finite state
                                                          //!< machine.
            size_t                     mCount;            //!< The number of
                                                          //!< transitions in
                                                          //!< the finite state
                                                          //!< machine's state
                                                          //!< transition
                                                          //!< table.
            const Transition *         mFirstTransition;  //!< The first
                                                          //!< transition in
                                                          //!< the finite state
                                                          //!< machine's state
                                                          //!< transition
                                                          //!< table.
        };

    }; // namespace Fsm

}; // namespace nl

#endif // NLFSM_MACHINE_HPP
