//
// Manta - Structural Variant and Indel Caller
// Copyright (c) 2013-2018 Illumina, Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//

/// \file
/// \brief Utility functions for mocking bam alignment data during unit testing
/// \author Trevor Ramsay
///

#pragma once

#include "htsapi/bam_record.hh"
#include "htsapi/bam_header_info.hh"

#include <string>


/// \brief Return a test bam_header_info object with references 0 and 1: "chr1" and "chr2", both size 500
bam_header_info
buildTestBamHeader();

/// \brief Build a bam_record based on the input parameters.
///        A default bam_record is a proper paired reference sequence.
void
buildTestBamRecord(
    bam_record& bamRead,
    int targetID = 0,
    int pos = 100,
    int mateTargetID = 0,
    int matePos = 200,
    int fragmentSize = 100,
    int mapQ = 15,
    std::string cigarString = "",
    std::string querySeq = "");


/// \brief Add supplementary alignment evidence to a bam record
///
/// This fills in an auxilliary "SA" tag, defaulting to a supplementary connections to "chrT"
/// from the default bam_header_info.
void
addSupplementaryAlignmentEvidence(
    bam_record& bamRead,
    const std::string& svStr = "chr1,300,-,54H22M,50,0;");

/// \brief Change the templateSize of the bam record.
inline
void
changeTemplateSize(
    bam_record& bamRead,
    int newSize)
{
    bam1_t* bamDataPtr(bamRead.get_data());
    bamDataPtr->core.isize = newSize;
}