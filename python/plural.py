import re

def plural(noun):
	if re.search('[sxz]$', noun):	# �����ű�ʾ��ƥ����Щ�ַ�������֮һ��
		return re.sub('$', 'es', noun)	# �� re.sub() ����ִ�л���������ʽ���ַ����滻��
	elif re.search('[^aeioudgkprt]h$', noun):
		return re.sub('$', 'es', noun)
	elif re.search('[^aeiou]y$', noun):
		return re.sub('y$', 'ies', noun)
	else:
		return noun + 's'
		