'use strict';

var Fs = require("fs");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");

Jest.describe("content", (function (param) {
        return Jest.test("non-zero length", (function (param) {
                      var match = typeof __filename === "undefined" ? undefined : __filename;
                      return Jest.ExpectJs.toBeTruthy(Jest.ExpectJs.expect(match !== undefined ? Fs.readFileSync(match, "utf8").length : 0));
                    }));
      }));

/*  Not a pure module */
