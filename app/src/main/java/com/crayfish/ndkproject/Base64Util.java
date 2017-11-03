package com.crayfish.ndkproject;

/**
 * ============================
 * 作    者：crayfish(徐杰)
 * 创建日期：2017/11/1.
 * 描    述：
 * 修改历史：
 * ===========================
 */

public class Base64Util {

    public static native String b64_encode(String str);
    public static native String b64_decode(String str);
}
