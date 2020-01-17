'use strict';

var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Path = require("path");

Jest.describe("join", (function (param) {
        return Jest.test("concat paths with sep", (function (param) {
                      return Jest.Expect.toEqual("a/b", Jest.Expect.expect(Path.join("a", "b")));
                    }));
      }));

/*  Not a pure module */
