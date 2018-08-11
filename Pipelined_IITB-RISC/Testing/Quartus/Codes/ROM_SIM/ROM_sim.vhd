library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

entity ROM_SIM is
	generic(num_words: integer := 256;
		word_length: integer := 16);
	port(
		address: in std_logic_vector(15 downto 0);
		data_out: out std_logic_vector(word_length-1 downto 0);
		rd_ena ,clk : in std_logic);
end entity;

architecture behave of ROM_SIM is
	type int_array is array (0 to num_words-1) of integer;
	signal memory: int_array := (others => 0);
	signal address_concat: std_logic_vector(integer(ceil(log2(real(num_words))))-1 downto 0);
begin

	address_concat <= address(integer(ceil(log2(real(num_words))))-1 downto 0);
	process(rd_ena, address_concat)
	begin
		data_out <= std_logic_vector(to_unsigned(memory(to_integer(unsigned(address_concat))),word_length));
	end process;

	memory(0) <= 4114;

end architecture;