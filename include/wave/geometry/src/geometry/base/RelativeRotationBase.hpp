/**
 * @file
 * @author lkoppel
 */

#ifndef WAVE_GEOMETRY_RELATIVEROTATIONBASE_HPP
#define WAVE_GEOMETRY_RELATIVEROTATIONBASE_HPP

namespace wave {

/** Base class for expressions representing a difference in orientations, in so(3).
 *
 * This class is inherited by expressions types which represent an element of @f$ so(3)
 * @f$, and which evaluate to RelativeRotation.
 *
 * @see RelativeRotation
 * */
template <typename Derived>
struct RelativeRotationBase : public VectorBase<Derived> {
    template <typename T>
    using BaseTmpl = RelativeRotationBase<T>;
};

/** Takes exponential map of an so(3) element */
template <typename Rhs>
auto exp(const RelativeRotationBase<Rhs> &rhs) {
    return ExpMap<internal::cr_arg_t<Rhs>>{rhs.derived()};
}
WAVE_OVERLOAD_FUNCTION_FOR_RVALUE(exp, ExpMap, RelativeRotationBase)


}  // namespace wave
#endif  // WAVE_GEOMETRY_RELATIVEROTATIONBASE_HPP
