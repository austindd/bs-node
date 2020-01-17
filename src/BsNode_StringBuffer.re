type t; /* can be either string or buffer */

type stringBufferKind(_) =
  | String: stringBufferKind(Js.String.t)
  | Buffer: stringBufferKind(BsNode_Buffer.t);

/** We except a good inliner will eliminate such boxing in the future */

let test = (type a, x: t): (stringBufferKind(a), a) =>
  if (Js.typeof(x) == "string") {
    (Obj.magic(String): stringBufferKind(a), Obj.magic(x): a);
  } else {
    (Obj.magic(Buffer): stringBufferKind(a), Obj.magic(x): a);
  };
