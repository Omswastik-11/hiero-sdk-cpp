// SPDX-License-Identifier: Apache-2.0
#include "BaseIntegrationTest.h"
#include "NodeDeleteTransaction.h"
#include "TransactionRecord.h"
#include "TransactionResponse.h"

#include <gtest/gtest.h>

using namespace Hiero;

class NodeDeleteTransactionIntegrationTests : public BaseIntegrationTest
{
protected:
  [[nodiscard]] const uint64_t& getNodeId() const { return mNodeId; }

private:
  const uint64_t mNodeId = 1;
};

//-----
TEST_F(NodeDeleteTransactionIntegrationTests, CanExecuteNodeDeleteTransaction)
{
  // Given / When / Then
  TransactionResponse txResponse;

  ASSERT_NO_THROW(
    txResponse = NodeDeleteTransaction().setNodeId(getNodeId()).freezeWith(&getTestClient()).execute(getTestClient()));

  TransactionReceipt txReceipt;
  ASSERT_NO_THROW(txReceipt = txResponse.getReceipt(getTestClient()));
}