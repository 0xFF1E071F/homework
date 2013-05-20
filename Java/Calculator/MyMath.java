import java.math.BigDecimal;

/**
 * ����������
 */
public class MyMath {
	// ����С����λ��
	public static final int DEFAULT_SCALE = 20;

	/**
	 * Ϊһ�����ִ���BigDecimal����
	 * @param number
	 * @return
	 */
	private static BigDecimal getBigDecimal(double number) {
		return new BigDecimal(number);
	}
	/**
	 * �ӷ�
	 * 
	 * @param num1
	 *            double
	 * @param num2
	 *            double
	 * @param reutrn
	 *            double ������ӵĽ��
	 */
	public static double add(double num1, double num2) {
		BigDecimal first = getBigDecimal(num1);
		BigDecimal second = getBigDecimal(num2);
		return first.add(second).doubleValue();
	}

	/**
	 * ����
	 * 
	 * @param num1
	 *            double
	 * @param num2
	 *            double
	 * @param reutrn
	 *            double ��������Ľ��
	 */
	public static double subtract(double num1, double num2) {
		BigDecimal first = getBigDecimal(num1);
		BigDecimal second = getBigDecimal(num2);
		return first.subtract(second).doubleValue();
	}

	/**
	 * �˷�
	 * 
	 * @param num1
	 *            double
	 * @param num2
	 *            double
	 * @param reutrn
	 *            double ������˵Ľ��
	 */
	public static double multiply(double num1, double num2) {
		BigDecimal first = getBigDecimal(num1);
		BigDecimal second = getBigDecimal(num2);
		return first.multiply(second).doubleValue();
	}

	/**
	 * ����
	 * 
	 * @param num1
	 *            double
	 * @param num2
	 *            double
	 * @param reutrn
	 *            double ��������Ľ��
	 */
	public static double divide(double num1, double num2) {
		BigDecimal first = getBigDecimal(num1);
		BigDecimal second = getBigDecimal(num2);
		return first.divide(second, DEFAULT_SCALE, BigDecimal.ROUND_HALF_UP)
				.doubleValue();
	}

}