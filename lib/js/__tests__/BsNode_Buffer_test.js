'use strict';

var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");

Jest.describe("readDoubleBigEndianNoAssert", (function (param) {
        Jest.test("valid offset", (function (param) {
                return Jest.Expect.toBeCloseTo(8.207e-304, Jest.Expect.expect(Buffer.from(/* array */[
                                      1,
                                      2,
                                      3,
                                      4,
                                      5,
                                      6,
                                      7,
                                      8
                                    ]).readDoubleBE(0, true)));
              }));
        return Jest.Skip.test("offset out of bounds", (function (param) {
                      return Jest.Expect.toThrow(Jest.Expect.expect((function (param) {
                                        return Buffer.from(/* array */[
                                                      1,
                                                      2,
                                                      3,
                                                      4,
                                                      5,
                                                      6,
                                                      7,
                                                      8
                                                    ]).readDoubleBE(1, true);
                                      })));
                    }));
      }));

/*  Not a pure module */
