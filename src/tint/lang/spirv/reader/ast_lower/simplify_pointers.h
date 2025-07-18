// Copyright 2021 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef SRC_TINT_LANG_SPIRV_READER_AST_LOWER_SIMPLIFY_POINTERS_H_
#define SRC_TINT_LANG_SPIRV_READER_AST_LOWER_SIMPLIFY_POINTERS_H_

#include "src/tint/lang/spirv/reader/ast_lower/transform.h"

namespace tint::ast::transform {

/// SimplifyPointers is a Transform that moves all usage of function-scope
/// `let` statements of a pointer type into their places of usage, while also
/// simplifying any chains of address-of or indirections operators.
///
/// Parameters of a pointer type are not adjusted.
///
/// Note: SimplifyPointers does not operate on module-scope `let`s, as these
/// cannot be pointers: https://gpuweb.github.io/gpuweb/wgsl/#module-constants
/// `A module-scope let-declared constant must be of constructible type.`
///
/// @note Depends on the following transforms to have been run first:
/// * Unshadow
class SimplifyPointers final : public Castable<SimplifyPointers, Transform> {
  public:
    /// Constructor
    SimplifyPointers();

    /// Destructor
    ~SimplifyPointers() override;

    /// @copydoc Transform::Apply
    ApplyResult Apply(const Program& program,
                      const DataMap& inputs,
                      DataMap& outputs) const override;

  private:
    struct State;
};

}  // namespace tint::ast::transform

#endif  // SRC_TINT_LANG_SPIRV_READER_AST_LOWER_SIMPLIFY_POINTERS_H_
