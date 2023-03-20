#include "rlog/RLogNode.h"

namespace rlog
{
   RLogNode::RLogNode() {}
   RLogNode::~RLogNode() {}

   void RLogNode::clear() {}
   void RLogNode::publish(const RLogData &data) {}
   void RLogNode::addPublisher(RLogNode *) {}
   void RLogNode::dropPublisher(RLogNode *, bool callbacks) {}
   bool RLogNode::enabled() const { return false; }
   void RLogNode::addSubscriber(RLogNode *) {}
   void RLogNode::dropSubscriber(RLogNode *) {}
   void RLogNode::isInterested(RLogNode *node, bool isInterested) {}
   void RLogNode::setEnabled(bool newState) {}
}