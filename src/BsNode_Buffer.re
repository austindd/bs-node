open Js.Typed_array;

type t;

[@bs.val] external fromString: Js.String.t => t = "Buffer.from";
[@bs.val] external fromStringWithEncoding: (Js.String.t, ~encoding: Js.String.t) => t = "Buffer.from";
[@bs.val] external fromArray: array(int) => t = "Buffer.from";
[@bs.val] external fromArrayBuffer: ArrayBuffer.t => t = "Buffer.from";
[@bs.val] external fromArrayBufferOffset: (ArrayBuffer.t, ~offset: int) => t = "Buffer.from";
[@bs.val] external fromArrayBufferRange: (ArrayBuffer.t, ~offset: int, ~length: int) => t = "Buffer.from";
[@bs.val] external fromBuffer: t => t = "Buffer.from";

[@bs.val] external alloc: int => t = "Buffer.alloc";
[@bs.val] external allocFillInt: (int, ~fill: int) => t = "Buffer.alloc";
[@bs.val] external allocFillString: (int, ~fill: Js.String.t) => t = "Buffer.alloc";
[@bs.val] external allocFillStringWithEncoding: (int, ~fill: Js.String.t, ~encoding: Js.String.t) => t = "Buffer.alloc";
[@bs.val] external allocFillBuffer: (int, ~fill: t) => t = "Buffer.alloc";
[@bs.val] external allocUnsafe: int => t = "Buffer.allocUnsafe";
[@bs.val] external allocUnsafeSlow: int => t = "Buffer.allocUnsafeSlow";

[@bs.get_index] external unsafeGet: (t, int) => int = "";
[@bs.set_index] external unsafeSet: (t, int, int) => unit = "";

[@bs.val] external byteLengthString: Js.String.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthStringWithEncoding: (Js.String.t, ~encoding: Js.String.t) => int = "Buffer.byteLength";
[@bs.val] external byteLengthBuffer: t => int = "Buffer.byteLength";
[@bs.val] external byteLengthInt8Array: Int8Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthUint8Array: Uint8Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthInt16Array: Int16Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthUint16Array: Uint16Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthInt32Array: Int32Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthUint32Array: Uint32Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthFloat32Array: Float32Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthFloat64Array: Float64Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthDataView: DataView.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthArrayBuffer: ArrayBuffer.t => int = "Buffer.byteLength";

[@bs.val] external compare: (t, t) => int = "Buffer.compare";

[@bs.val] external concat: array(t) => t = "Buffer.concat";
[@bs.val] external concatLength: (array(t), ~length: int) => t = "Buffer.concat";

[@bs.val] external isEncoding: Js.String.t => bool = "Buffer.isEncoding";

type buffer;
[@bs.val] external buffer: buffer = "Buffer";
[@bs.val] external poolSize: int = "Buffer.poolSize";
[@bs.set] external setPoolSize: (buffer, int) => int = "poolSize";
let setPoolSize = n => setPoolSize(buffer, n);

[@bs.send] external copy: (t, t) => int = "copy";
[@bs.send] external copyOffset: (t, t, ~targetStart: int) => int = "copy";
[@bs.send] external copyOffsetFromOffset: (t, t, ~targetStart: int, ~sourceStart: int) => int = "copy";
[@bs.send] external copyOffsetFromRange: (t, t, ~targetStart: int, ~sourceStart: int, ~sourceEnd: int) => int = "copy";
[@bs.send] external copyToUint8Array: (t, Uint8Array.t) => int = "copy";
[@bs.send] external copyToUint8ArrayOffset: (t, Uint8Array.t, ~targetStart: int) => int = "copy";
[@bs.send] external copyToUint8ArrayFrom: (t, Uint8Array.t, ~targetStart: int, ~sourceStart: int) => int = "copy";
[@bs.send] external copyToUint8ArrayFromRange: (t, Uint8Array.t, ~targetStart: int, ~sourceStart: int, ~sourceEnd: int) => int = "copy";

/* FIXME after iterators support */
/* external entries : t -> Iterator = "" [@@bs.get] */

[@bs.send] external equals: (t, t) => bool = "equals";

[@bs.send] external fillString: (t, Js.String.t) => t = "fill";
[@bs.send] external fillStringOffset: (t, ~value: Js.String.t, ~offset: int) => t = "fill";
[@bs.send] external fillStringRange: (t, ~value: Js.String.t, ~offset: int, ~end_: int) => t = "fill";
[@bs.send] external fillStringRangeWithEncoding: (t, ~value: Js.String.t, ~offset: int, ~end_: int, ~encoding: Js.String.t) => t = "fill";
[@bs.send] external fillBuffer: (t, t) => t = "fill";
[@bs.send] external fillBufferOffset: (t, ~value: t, ~offset: int) => t = "fill";
[@bs.send] external fillBufferRange: (t, ~value: t, ~offset: int, ~end_: int) => t = "fill";
[@bs.send] external fillInt: (t, int) => t = "fill";
[@bs.send] external fillIntOffset: (t, ~value: int, ~offset: int) => t = "fill";
[@bs.send] external fillIntRange: (t, ~value: int, ~offset: int, ~end_: int) => t = "fill";

[@bs.send] external includesString: (t, Js.String.t) => bool = "includes";
[@bs.send] external includesStringFrom: (t, ~value: Js.String.t, ~offset: int) => bool = "includes";
[@bs.send] external includesStringWithEncodingFrom: (t, ~value: Js.String.t, ~offset: int, ~encoding: Js.String.t) => bool = "includes";
[@bs.send] external includesBuffer: (t, t) => bool = "includes";
[@bs.send] external includesBufferFrom: (t, ~value: t, ~offset: int) => bool = "includes";
[@bs.send] external includesInt: (t, int) => bool = "includes";
[@bs.send] external includesIntFrom: (t, ~value: int, ~offset: int) => bool = "includes";

[@bs.send] external indexOfString: (t, Js.String.t) => int = "indexOf";
[@bs.send] external indexOfStringFrom: (t, ~value: Js.String.t, ~offset: int) => int = "indexOf";
[@bs.send] external indexOfStringWithEncodingFrom: (t, ~value: Js.String.t, ~offset: int, ~encoding: Js.String.t) => int = "indexOf";
[@bs.send] external indexOfBuffer: (t, t) => int = "indexOf";
[@bs.send] external indexOfBufferFrom: (t, ~value: t, ~offset: int) => int = "indexOf";
[@bs.send] external indexOfInt: (t, int) => int = "indexOf";
[@bs.send] external indexOfIntFrom: (t, ~value: int, ~offset: int) => int = "indexOf";

/* FIXME after iterators support */
/* external keys : t -> Iterator = "" [@@bs.send] */

[@bs.send] external lastIndexOfString: (t, Js.String.t) => int = "lastIndexOf";
[@bs.send] external lastIndexOfStringFrom: (t, ~value: Js.String.t, ~offset: int) => int = "lastIndexOf";
[@bs.send] external lastIndexOfStringWithEncodingFrom: (t, ~value: Js.String.t, ~offset: int, ~encoding: Js.String.t) => int = "lastIndexOf";
[@bs.send] external lastIndexOfBuffer: (t, t) => int = "lastIndexOf";
[@bs.send] external lastIndexOfBufferFrom: (t, ~value: t, ~offset: int) => int = "lastIndexOf";
[@bs.send] external lastIndexOfInt: (t, int) => int = "lastIndexOf";
[@bs.send] external lastIndexOfIntFrom: (t, ~value: int, ~offset: int) => int = "lastIndexOf";

[@bs.get] external length: t => int = "length";

[@bs.send] external readDoubleBigEndian: (t, ~offset: int) => float = "readDoubleBigEndian";
[@bs.send] external readDoubleBigEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readDoubleBE";

[@bs.send] external readDoubleLittleEndian: (t, ~offset: int) => float = "readDoubleLittleEndian";
[@bs.send] external readDoubleLittleEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readDoubleLE";

[@bs.send] external readFloatBigEndian: (t, ~offset: int) => float = "readFloatBigEndian";
[@bs.send] external readFloatBigEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readFloatBE";

[@bs.send] external readFloatLittleEndian: (t, ~offset: int) => float = "readFloatLittleEndian";
[@bs.send] external readFloatLittleEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readFloatLE";

[@bs.send] external readInt8: (t, ~offset: int) => float = "readInt8";
[@bs.send] external readInt8NoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readInt8";

[@bs.send] external readInt16BigEndian: (t, ~offset: int) => float = "readInt16BigEndian";
[@bs.send] external readInt16BigEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readInt16BE";

[@bs.send] external readInt16LittleEndian: (t, ~offset: int) => float = "readInt16LittleEndian";
[@bs.send] external readInt16LittleEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readInt16LE";

[@bs.send] external readInt32BigEndian: (t, ~offset: int) => float = "readInt32BigEndian";
[@bs.send] external readInt32BigEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readInt32BE";

[@bs.send] external readInt32LittleEndian: (t, ~offset: int) => float = "readInt32LittleEndian";
[@bs.send] external readInt32LittleEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readInt32LE";

[@bs.send] external readIntBigEndian: (t, ~offset: int, ~length: int) => float = "readIntBigEndian";
[@bs.send] external readIntBigEndianNoAssert: (t, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "readIntBE";

[@bs.send] external readIntLittleEndian: (t, ~offset: int, ~length: int) => float = "readIntLittleEndian";
[@bs.send] external readIntLittleEndianNoAssert: (t, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "readIntLE";

[@bs.send] external readUint8: (t, ~offset: int) => float = "readUint8";
[@bs.send] external readUint8NoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readUint8";

[@bs.send] external readUint16BigEndian: (t, ~offset: int) => float = "readUint16BigEndian";
[@bs.send] external readUint16BigEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readUint16BE";

[@bs.send] external readUint16LittleEndian: (t, ~offset: int) => float = "readUint16LittleEndian";
[@bs.send] external readUint16LittleEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readUint16LE";

[@bs.send] external readUint32BigEndian: (t, ~offset: int) => float = "readUint32BigEndian";
[@bs.send] external readUint32BigEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readUint32BE";

[@bs.send] external readUint32LittleEndian: (t, ~offset: int) => float = "readUint32LittleEndian";
[@bs.send] external readUint32LittleEndianNoAssert: (t, ~offset: int, [@bs.as {json|true|json}] _) => float = "readUint32LE";

[@bs.send] external readUintBigEndian: (t, ~offset: int, ~length: int) => float = "readUintBigEndian";
[@bs.send] external readUintBigEndianNoAssert: (t, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "readUintBE";

[@bs.send] external readUintLittleEndian: (t, ~offset: int, ~length: int) => float = "readUintLittleEndian";
[@bs.send] external readUintLittleEndianNoAssert: (t, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "readUintLE";

[@bs.send] external slice: t => t = "slice";
[@bs.send] external sliceOffset: (t, ~start: int) => t = "slice";
[@bs.send] external sliceRange: (t, ~start: int, ~end_: int) => t = "slice";

[@bs.send] external swap16: t => t = "swap16";
[@bs.send] external swap32: t => t = "swap32";
[@bs.send] external swap64: t => t = "swap64";

[@bs.send] external toJSON: t => Js.t({..}) = "toJSON";

[@bs.send] external toString: t => Js.String.t = "toString";

[@bs.send] external toStringWithEncoding: (t, ~encoding: Js.String.t) => Js.String.t = "toString";
[@bs.send] external toStringWithEncodingOffset: (t, ~encoding: Js.String.t, ~start: int) => Js.String.t = "toString";
[@bs.send] external toStringWithEncodingRange: (t, ~encoding: Js.String.t, ~start: int, ~end_: int) => Js.String.t = "toString";

/* FIXME after iterators support */
/* external values : t -> Iterator = "" [@@bs.get] */

[@bs.send] external write: (t, Js.String.t) => int = "write";
[@bs.send] external writeOffset: (t, ~value: Js.String.t, ~offset: int) => int = "write";
[@bs.send] external writeRange: (t, ~value: Js.String.t, ~offset: int, ~length: int) => int = "write";
[@bs.send] external writeRangeWithEncoding:
  (
    t,
    ~value: Js.String.t,
    ~offset: int,
    ~length: int,
    ~encoding: Js.String.t
  ) => int = "write";

[@bs.send] external writeDoubleBigEndian: (t, ~value: float, ~offset: int) => float = "writeDoubleBigEndian";
[@bs.send] external writeDoubleBigEndianNoAssert: (t, ~value: float, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeDoubleBE";

[@bs.send] external writeDoubleLittleEndian: (t, ~value: float, ~offset: int) => float = "writeDoubleLittleEndian";
[@bs.send] external writeDoubleLittleEndianNoAssert: (t, ~value: float, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeDoubleLE";

[@bs.send] external writeFloatBigEndian: (t, ~value: float, ~offset: int) => float = "writeFloatBigEndian";
[@bs.send] external writeFloatBigEndianNoAssert: (t, ~value: float, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeFloatBE";

[@bs.send] external writeFloatLittleEndian: (t, ~value: float, ~offset: int) => float = "writeFloatLittleEndian";
[@bs.send] external writeFloatLittleEndianNoAssert: (t, ~value: float, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeFloatLE";

[@bs.send] external writeInt8: (t, ~value: int, ~offset: int) => float = "writeInt8";
[@bs.send] external writeInt8NoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeInt8";

[@bs.send] external writeInt16BigEndian: (t, ~value: int, ~offset: int) => float = "writeInt16BigEndian";
[@bs.send] external writeInt16BigEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeInt16BE";

[@bs.send] external writeInt16LittleEndian: (t, ~value: int, ~offset: int) => float = "writeInt16LittleEndian";
[@bs.send] external writeInt16LittleEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeInt16LE";

[@bs.send] external writeInt32BigEndian: (t, ~value: int, ~offset: int) => float = "writeInt32BigEndian";
[@bs.send] external writeInt32BigEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeInt32BE";

[@bs.send] external writeInt32LittleEndian: (t, ~value: int, ~offset: int) => float = "writeInt32LittleEndian";
[@bs.send] external writeInt32LittleEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeInt32LE";

[@bs.send] external writeIntBigEndian: (t, ~value: int, ~offset: int, ~length: int) => float = "writeIntBigEndian";
[@bs.send] external writeIntBigEndianNoAssert: (t, ~value: int, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "writeIntBE";

[@bs.send] external writeIntLittleEndian: (t, ~value: int, ~offset: int, ~length: int) => float = "writeIntLittleEndian";
[@bs.send] external writeIntLittleEndianNoAssert: (t, ~value: int, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "writeIntLE";

[@bs.send] external writeUint8: (t, ~value: int, ~offset: int) => float = "writeUint8";
[@bs.send] external writeUint8NoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeUint8";

[@bs.send] external writeUint16BigEndian: (t, ~value: int, ~offset: int) => float = "writeUint16BigEndian";
[@bs.send] external writeUint16BigEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeUint16BE";

[@bs.send] external writeUint16LittleEndian: (t, ~value: int, ~offset: int) => float = "writeUint16LittleEndian";
[@bs.send] external writeUint16LittleEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeUint16LE";

[@bs.send] external writeUint32BigEndian: (t, ~value: int, ~offset: int) => float = "writeUint32BigEndian";
[@bs.send] external writeUint32BigEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeUint32BE";

[@bs.send] external writeUint32LittleEndian: (t, ~value: int, ~offset: int) => float = "writeUint32LittleEndian";
[@bs.send] external writeUint32LittleEndianNoAssert: (t, ~value: int, ~offset: int, [@bs.as {json|true|json}] _) => float = "writeUint32LE";

[@bs.send] external writeUintBigEndian: (t, ~value: int, ~offset: int, ~length: int) => float = "writeUintBigEndian";
[@bs.send] external writeUintBigEndianNoAssert: (t, ~value: int, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "writeUintBE";

[@bs.send] external writeUintLittleEndian: (t, ~value: int, ~offset: int, ~length: int) => float = "writeUintLittleEndian";
[@bs.send] external writeUintLittleEndianNoAssert: (t, ~value: int, ~offset: int, ~length: int, [@bs.as {json|true|json}] _) => float = "writeUintLE";

[@bs.get] external _INSPECT_MAX_BYTES: t => int = "INSPECT_MAX_BYTES";

[@bs.get] external kMaxLength: t => int = "kMaxLength";

[@bs.send] external transcode: (t, ~source: t, ~from: Js.String.t, ~to_: Js.String.t) => t = "transcode";