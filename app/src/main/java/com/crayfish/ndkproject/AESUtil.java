package com.crayfish.ndkproject;

/**
 * ============================
 * 作    者：crayfish(徐杰)
 * 创建日期：2017/9/30.
 * 描    述：
 * 修改历史：
 * ===========================
 */

public class AESUtil {

    static {
        System.loadLibrary("AESUtilsJni");
    }

    public static  native String encrypt(String plainText, String key);
    public static  native String decrypt(String cipherText, String key);
}
