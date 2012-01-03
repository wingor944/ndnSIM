/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2011 UCLA
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author:  Alexander Afanasyev <alexander.afanasyev@ucla.edu>
 */

#ifndef CCNX_TRACE_HELPER_H
#define CCNX_TRACE_HELPER_H

#include "ns3/nstime.h"
#include "ns3/event-id.h"

#include <list>

namespace ns3 {

class CcnxAppTracer;
class CcnxL3Tracer;
class Ipv4AppTracer;

class CcnxTraceHelper
{
public:
  CcnxTraceHelper ();
  
  /**
   * @brief Destructor that invokes trace output procedures
   */
  ~CcnxTraceHelper ();

  /**
   * @brief Set filename to output app trace.
   *
   * By default, trace is output to NS_LOG_INFO stream
   *
   * @param file File where trace will be written to
   */
  void
  SetAppTraceFile (const std::string &appTrace = "apps.log");

  /**
   * @brief Set filename to output app trace.
   *
   * By default, trace is output to NS_LOG_INFO stream
   *
   * @param file File where trace will be written to
   */
  void
  SetL3TraceFile (const std::string &l3Trace = "l3.log");

  /**
   * @brief Enable aggregate app-level CCNx tracing on all CCNx applications
   *
   * @param app  Class name of the application of interest
   */
  void
  EnableAggregateAppAll (const std::string &app);

  /**
   * @brief Enable aggregate network-level CCNx tracing on all CCNx node
   */
  void
  EnableAggregateL3All ();

  /**
   * @brief Enable network-level CCNx rate tracing on all CCNx nodes
   */
  void
  EnableRateL3All (const std::string &l3RateTrace = "l3-rate.log");
  
  /**
   * @brief Enable app-level CCNx sequence tracing on all CCNx applications
   */
  void
  EnableSeqsAppAll (const std::string &app, const std::string &appSeqsTrace = "app-seqs.log");

  /**
   * @brief Enable app-level IPv4 sequence tracing on all nodes (BulkSender + PacketSink)
   */
  void
  EnableIpv4SeqsAppAll (const std::string &appSeqsTrace = "app-seqs.log");
  
private:
  std::string m_appTrace;
  std::list<Ptr<CcnxAppTracer> > m_apps;

  std::string m_l3Trace;
  std::list<Ptr<CcnxL3Tracer> > m_l3s;

  std::list<Ptr<CcnxL3Tracer> > m_l3Rates;
  std::ostream *m_l3RateTrace;

  std::list<Ptr<CcnxAppTracer> > m_appSeqs;
  std::ostream *m_appSeqsTrace;

  std::list<Ptr<Ipv4AppTracer> > m_ipv4AppSeqs;
  std::ostream *m_ipv4AppSeqsTrace;
};


} // namespace ns3

#endif /* CCNX_TRACE_HELPER_H */
