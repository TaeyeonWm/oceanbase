/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_SQL_OB_EXPR_GREATER_EQUAL_H_
#define OCEANBASE_SQL_OB_EXPR_GREATER_EQUAL_H_
#include "sql/engine/expr/ob_expr_operator.h"
#include "lib/ob_name_def.h"
#include "share/object/ob_obj_cast.h"
namespace oceanbase {
namespace sql {
class ObExprGreaterEqual : public ObRelationalExprOperator {
  public:
  ObExprGreaterEqual();
  explicit ObExprGreaterEqual(common::ObIAllocator& alloc);
  virtual ~ObExprGreaterEqual(){};
  virtual int calc_result2(
      common::ObObj& result, const common::ObObj& obj1, const common::ObObj& obj2, common::ObExprCtx& expr_ctx) const;
  virtual int calc_resultN(
      common::ObObj& result, const common::ObObj* objs_stack, int64_t param_num, common::ObExprCtx& expr_ctx) const;

  virtual int cg_expr(ObExprCGCtx& expr_cg_ctx, const ObRawExpr& raw_expr, ObExpr& rt_expr) const override
  {
    return ObRelationalExprOperator::cg_expr(expr_cg_ctx, raw_expr, rt_expr);
  }

  private:
  DISALLOW_COPY_AND_ASSIGN(ObExprGreaterEqual);
};
}  // end namespace sql
}  // end namespace oceanbase

#endif  // OCEANBASE_SQL_OB_EXPR_GREATER_EQUAL_H_
