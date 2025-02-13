//
// SPDX-FileCopyrightText: 2020 Friedrich-Alexander University Erlangen-Nuernberg (FAU), Computer Science 7 - Computer Networks and Communication Systems
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

/*
 *
 * Part of 5G-Sim-V2I/N
 *
 *
 */

#pragma once

#include "stack/mac/scheduler/LteSchedulerEnbUl.h"
#include "stack/mac/layer/LteMacEnb.h"
#include "stack/mac/buffer/harq/LteHarqBufferRx.h"
#include "stack/mac/buffer/harq/LteHarqBufferTx.h"
#include "stack/mac/allocator/LteAllocationModule.h"
#include "stack/mac/scheduler/LteScheduler.h"
#include "stack/mac/buffer/LteMacBuffer.h"
#include "nr/stack/mac/scheduling_modules/NRQoSModel.h"

//see inherit class for method description
class NRSchedulerGnbUl: public LteSchedulerEnbUl {
protected:

	std::set<MacNodeId> schedulingNodeSet;

	virtual LteMacScheduleListWithSizes* schedule();

	virtual bool racschedule();

	virtual bool rtxschedule();

	virtual bool rtxscheduleWithNRHarq();

	virtual unsigned int schedulePerAcidRtx(MacNodeId nodeId, Codeword cw, unsigned char acid, std::vector<BandLimit> *bandLim = NULL, Remote antenna = MACRO, bool limitBl = false);

	virtual unsigned int schedulePerAcidRtxWithNRHarq(MacNodeId nodeId, Codeword cw, unsigned char acid, std::vector<BandLimit> *bandLim = NULL, Remote antenna = MACRO, bool limitBl = false);

	virtual unsigned int scheduleGrant(MacCid cid, unsigned int bytes, bool& terminate, bool& active, bool& eligible, std::vector<BandLimit>* bandLim = NULL, Remote antenna = MACRO, bool limitBl = false);

	virtual void qosModelSchedule();

	virtual void removePendingRac(MacNodeId nodeId);

	/**
	 * Set Direction and bind the internal pointers to the MAC objects.
	 * @param dir link direction
	 * @param mac pointer to MAC module
	 */
	virtual void initialize(Direction dir, LteMacEnb *mac);
};
