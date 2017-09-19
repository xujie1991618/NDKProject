package com.crayfish.ndkproject;

/**
 * ============================
 * 作    者：crayfish(徐杰)
 * 创建日期：2017/9/15.
 * 描    述：
 * 修改历史：
 * ===========================
 */

public class NdkTest {
    // new code
    static {
        System.loadLibrary("HelloJniLibName");
    }
    public native String getString();
}
