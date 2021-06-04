from distutils.core import setup, Extension

module1 = Extension( 
	'XXX', # module name in interpreter
	sources = ['XXX.c'] 
)

setup( 
	name = 'XXX',
	version = '1.1',
	description = 'Simple module',
	ext_modules= [module1]
)